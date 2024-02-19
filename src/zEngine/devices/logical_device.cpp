#include "logical_device.h"
#include <vector>
#include "asserts.h"

namespace zEngine::devices
{
    LogicalDevice::LogicalDevice(const PhysicalDevice &d)
    {
        auto infos = d.GetQueueFamilyInfos();
        float priority = 1.0f;

        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &priority;
        queueCreateInfo.queueFamilyIndex = infos.IndexOf(VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT);

        auto deviceFeatures = d.GetFeatures();

        VkDeviceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        createInfo.queueCreateInfoCount = 1; //TODO: Create multiple based on queue count on physical device.
        createInfo.pQueueCreateInfos = &queueCreateInfo;
        createInfo.pEnabledFeatures = &deviceFeatures;

        zEngine::common::Assert::VulkanSuccess(vkCreateDevice(d.GetVkPhysicalDevice(), &createInfo, nullptr, &vkDevice), "Failed to create logical device.");
    }

    LogicalDevice::~LogicalDevice()
    {
        if (vkDevice != nullptr)
        {
            vkDestroyDevice(vkDevice, nullptr);
            vkDevice = nullptr;
        }
    }
}