#include "logical_device.h"
#include <vulkan/vulkan.h>
#include "common/asserts.h"
#include "vk_builders/device_create_info_builder.h"
#include <set>
#include <algorithm>

namespace engine::devices
{
    LogicalDevice::LogicalDevice(const PhysicalDevice &physical_device, const common::config::Configuration &config)
        : physical_device_(physical_device)
    {
        float priority = 1.0f;
        const auto queues = physical_device.GetQueues();

        auto gfx_queue_info = queues.FirstOfType(VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT);

        std::vector<VkDeviceQueueCreateInfo> queue_create_infos {
            vk_builders::DeviceQueueCreateInfoBuilder(gfx_queue_info.index_, 1, &priority).Build()
        };

        const auto& deviceCreateInfo = vk_builders::DeviceCreateInfoBuilder()
            .AddExtensions(config.vulkan_settings_.device_extensions_)
            .AddQueue(queue_create_infos)
            .Build();
        
        common::Assert::VulkanSuccess(vkCreateDevice(physical_device.Vk(), &deviceCreateInfo, nullptr, &logical_device_), "Failed to create logical device.");

        CreateQueueContainer();

        VkQueue gfx_queue;
        vkGetDeviceQueue(logical_device_, gfx_queue_info.index_, 0, &gfx_queue);

        queue_container_->Register(gfx_queue_info, gfx_queue);

        command_pools_[gfx_queue_info.index_] = std::make_unique<engine::commands::CommandPool>(logical_device_, gfx_queue_info.index_);
    }

    LogicalDevice::~LogicalDevice()
    {
        for (auto &[key, value] : command_pools_)
        {
            value.reset();
        }

        command_pools_.clear();

        if (queue_container_ != nullptr)
        {
            queue_container_.reset();
        }

        if (logical_device_ != nullptr)
        {
            vkDestroyDevice(logical_device_, nullptr);
        }
    }

    void LogicalDevice::CreateQueueContainer()
    {
        queue_container_ = std::make_unique<QueueContainer>(logical_device_);
    }

    void LogicalDevice::CreateCommandPool()
    {
    }

    std::vector<uint32_t> LogicalDevice::GetPresentationQueues() const
    {
        return {
            queue_container_->GetAvailable(VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT).queue_info_.index_
        };
    }
}