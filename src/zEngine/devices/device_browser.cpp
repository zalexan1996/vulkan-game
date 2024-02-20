#include "device_browser.h"
#include <vulkan/vulkan.h>
#include "application.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "physical_device.h"
#include "app_settings.h"
#include "string.h"
#include "window.h"
namespace zEngine::devices
{

    VkPhysicalDevice DeviceBrowser::FindBest()
    {
        auto instance = Application::GetVkInstance();

        uint32_t count;
        vkEnumeratePhysicalDevices(instance, &count, nullptr);

        std::vector<VkPhysicalDevice> devices(count);
    
        vkEnumeratePhysicalDevices(instance, &count, devices.data());

        std::erase_if(devices, [&](VkPhysicalDevice d) {
            return !this->isSupported(d);
        });

        for (size_t i = 0; i < count; i++)
        {
            VkPhysicalDevice d = devices.at(i);
            VkPhysicalDeviceProperties prop;
            vkGetPhysicalDeviceProperties(d, &prop);
            if (prop.deviceType == VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
                return d;
            }
        }

        return devices.at(0);
    }

    bool areExtensionsSupported(VkPhysicalDevice d)
    {
        uint32_t count;
        std::vector<VkExtensionProperties> extensions;
        auto appSettings = zEngine::configuration::AppSettings();
        vkEnumerateDeviceExtensionProperties(d, nullptr, &count, nullptr);
        extensions.resize(count);

        vkEnumerateDeviceExtensionProperties(d, nullptr, &count, extensions.data());

        return std::all_of(appSettings.DeviceExtensions.begin(), appSettings.DeviceExtensions.end(), [&extensions](const char *ext) {
            return std::find_if(extensions.begin(), extensions.end(), [&ext](const VkExtensionProperties &p) {
                return strcmp(ext, p.extensionName);
            }) != extensions.end();
        });

    }
    
    bool isSwapchainSupported(VkPhysicalDevice d)
    {
        auto surfaceProp = Application::GetSingleton()->window->GetSurfaceCapabilities(d);
        return surfaceProp.IsSupported();
    }

    bool DeviceBrowser::isSupported(VkPhysicalDevice device)
    {
        return areExtensionsSupported(device) && isSwapchainSupported(device);
    }
}