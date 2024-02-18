#include "device_browser.h"
#include <vulkan/vulkan.h>
#include "application.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include "physical_device.h"

namespace zEngine::devices
{
    std::string getVersion(uint32_t version)
    {
        return std::to_string(VK_API_VERSION_MAJOR(version)) 
                + '.' 
                + std::to_string(VK_API_VERSION_MINOR(version))
                + '.'
                + std::to_string(VK_API_VERSION_PATCH(version));
    }

    std::string getDeviceTypeString(VkPhysicalDeviceType type)
    {
        switch(type)
        {
            case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
                return "INTEGRATED";
            case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
                return "DISCRETE";
            case VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_CPU:
                return "CPU";
            default:
                return "IDFK";
        }
    }

    void DeviceBrowser::FindBest()
    {
        auto instance = Application::GetVkInstance();

        uint32_t count;
        vkEnumeratePhysicalDevices(instance, &count, nullptr);

        std::vector<VkPhysicalDevice> devices(count);
    
        vkEnumeratePhysicalDevices(instance, &count, devices.data());

        std::cout << std::left << std::setw(15) << "apiVersion"
            << std::setw(15) << "DeviceType"
            << std::setw(40) << "DeviceName"
            << std::setw(15) << "Graphics #"
            << std::setw(15) << "Computer #"
            << std::setw(15) << "Transfer #"
            << std::endl;

        for (uint32_t i = 0; i < count; i++)
        {
            PhysicalDevice d = PhysicalDevice(devices.at(i));
            VkPhysicalDeviceProperties properties = d.GetProperties();
            auto queueCounts = d.GetQueueFamilyCounts();
            

            std::cout << std::left << std::setw(15) << getVersion(properties.apiVersion)
                << std::setw(15) << getDeviceTypeString(properties.deviceType)
                << std::setw(40) << properties.deviceName
                << std::setw(15) << queueCounts.graphics
                << std::setw(15) << queueCounts.compute
                << std::setw(15) << queueCounts.transfer
                << std::endl;
        }
    }
}