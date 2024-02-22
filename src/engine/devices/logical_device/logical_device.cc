#include "logical_device.h"
#include <vulkan/vulkan.h>
#include "common/asserts.h"
#include "vk_builders/device_create_info_builder.h"

namespace engine::devices
{
    LogicalDevice::LogicalDevice(const PhysicalDevice &physical_device, const common::config::Configuration &config)
        : physical_device_(physical_device)
    {
        float priority = 1.0f;
        const auto queues = physical_device.GetQueues();

        const auto &queueCreateInfo = vk_builders::DeviceQueueCreateInfoBuilder(0, 1, &priority).Build();

        const auto& deviceCreateInfo = vk_builders::DeviceCreateInfoBuilder()
            .AddExtensions(config.vulkan_settings_.device_extensions_)
            .AddQueue(queueCreateInfo)
            .Build();
        
        common::Assert::VulkanSuccess(vkCreateDevice(physical_device.Vk(), &deviceCreateInfo, nullptr, &logical_device_), "Failed to create logical device.");
    }

    LogicalDevice::~LogicalDevice()
    {
        if (logical_device_ != nullptr)
        {
            vkDestroyDevice(logical_device_, nullptr);
        }
    }
}