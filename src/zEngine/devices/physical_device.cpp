#include "physical_device.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace zEngine::devices
{
    PhysicalDevice::PhysicalDevice(VkPhysicalDevice device)
        : vkPhysicalDevice(device)
    {
        uint32_t count;
        std::vector<VkQueueFamilyProperties> props;

        vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &count, nullptr);
        props.resize(count);
        vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &count, props.data());
        
        queueFamilyInfos = QueueFamilyInfos(props, device);   
    }

    PhysicalDevice::PhysicalDevice(const PhysicalDevice &other)
        : vkPhysicalDevice(other.GetVkPhysicalDevice()), queueFamilyInfos(other.GetQueueFamilyInfos())
    { }

    VkPhysicalDeviceProperties PhysicalDevice::GetProperties() const
    {
        VkPhysicalDeviceProperties p;
        vkGetPhysicalDeviceProperties(vkPhysicalDevice, &p);

        return p;
    }

    const VkPhysicalDeviceFeatures PhysicalDevice::GetFeatures() const
    {
        VkPhysicalDeviceFeatures deviceFeatures{};
        vkGetPhysicalDeviceFeatures(vkPhysicalDevice, &deviceFeatures);

        return deviceFeatures;
    }

    void PhysicalDevice::Print() const
    {
    }
}