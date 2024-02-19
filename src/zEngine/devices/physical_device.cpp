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
        vkGetPhysicalDeviceQueueFamilyProperties(device, &count, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilyProperties(count);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &count, queueFamilyProperties.data());
    }

    VkPhysicalDeviceProperties PhysicalDevice::GetProperties() const
    {
        VkPhysicalDeviceProperties p;
        vkGetPhysicalDeviceProperties(vkPhysicalDevice, &p);

        return p;
    }
    
    const QueueFamilyInfos PhysicalDevice::GetQueueFamilyInfos() const
    {
        uint32_t count;
        std::vector<VkQueueFamilyProperties> props;

        vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &count, nullptr);
        props.resize(count);
        vkGetPhysicalDeviceQueueFamilyProperties(vkPhysicalDevice, &count, props.data());
        
        return QueueFamilyInfos(props);
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