#include "device_browser.h"
#include <vulkan/vulkan.h>
#include "application.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include "physical_device.h"

namespace zEngine::devices
{

    VkPhysicalDevice DeviceBrowser::FindBest()
    {
        auto instance = Application::GetVkInstance();

        uint32_t count;
        vkEnumeratePhysicalDevices(instance, &count, nullptr);

        std::vector<VkPhysicalDevice> devices(count);
    
        vkEnumeratePhysicalDevices(instance, &count, devices.data());

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
}