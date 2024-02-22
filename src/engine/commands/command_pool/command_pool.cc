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
}