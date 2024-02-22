#include "command_pool.h"
#include "common/asserts.h"

namespace engine::commands
{
    CommandPool::CommandPool(VkDevice device, uint32_t queue_family_index)
        : device_(device)
    {
        VkCommandPoolCreateInfo create_info{};
        create_info.sType = VkStructureType::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        create_info.queueFamilyIndex = queue_family_index;

        common::Assert::VulkanSuccess(vkCreateCommandPool(device, &create_info, nullptr, &pool_), "Failed to create a command pool.");
    }

    CommandPool::~CommandPool()
    {
        if (pool_ != nullptr)
        {
            vkDestroyCommandPool(device_, pool_, nullptr);
        }
    }

    void CommandPool::Allocate(uint32_t count)
    {
        VkCommandBufferAllocateInfo info{};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        info.commandPool = pool_;
        info.level = VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        info.commandBufferCount = count;

        common::Assert::VulkanSuccess(vkAllocateCommandBuffers(device_, &info, buffers_.data()), "Failed to allocate command buffers.");
    }
}