#include "physical_device.h"
#include <vector>

namespace zEngine::devices
{
    PhysicalDevice::PhysicalDevice(VkPhysicalDevice device)
        : vkPhysicalDevice(device)
    {
        uint32_t count;
        vkGetPhysicalDeviceQueueFamilyProperties(device, &count, nullptr);
        std::vector<VkQueueFamilyProperties> queueFamilyProperties(count);
        vkGetPhysicalDeviceQueueFamilyProperties(device, &count, queueFamilyProperties.data());

        for (uint32_t i = 0; i < count; i++)
        {
            const VkQueueFamilyProperties &p = queueFamilyProperties.at(i);

            if (p.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT)
            {
                queueFamilyCounts.graphics += p.queueCount;
            }
            if (p.queueFlags & VkQueueFlagBits::VK_QUEUE_COMPUTE_BIT)
            {
                queueFamilyCounts.compute += p.queueCount;
            }
            if (p.queueFlags & VkQueueFlagBits::VK_QUEUE_TRANSFER_BIT)
            {
                queueFamilyCounts.transfer += p.queueCount;
            }
        }
    }

    VkPhysicalDeviceProperties PhysicalDevice::GetProperties()
    {
        VkPhysicalDeviceProperties p;
        vkGetPhysicalDeviceProperties(vkPhysicalDevice, &p);

        return p;
    }
    
    const QueueFamilyCounts& PhysicalDevice::GetQueueFamilyCounts()
    {
        return queueFamilyCounts;
    }
}