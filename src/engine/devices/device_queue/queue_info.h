#pragma once
#include <vector>
#include "engine/engine_vulkan.h"

namespace engine::devices
{
    struct QueueInfo
    {
        QueueInfo() {};
        QueueInfo(uint32_t index, uint32_t flags, uint32_t count);

        uint32_t index_ = -1;
        uint32_t flags_ = -1;
        uint32_t count_ = -1;

        bool SupportsGraphics() const {
            return flags_ & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT;
        }
        bool SupportsCompute() const {
            return flags_ & VkQueueFlagBits::VK_QUEUE_COMPUTE_BIT;
        }
        bool SupportsTransfer() const {
            return flags_ & VkQueueFlagBits::VK_QUEUE_TRANSFER_BIT;
        }

        void Print() const;
    };

    struct QueueInfos
    {
        std::vector<QueueInfo> queue_infos_;
        QueueInfos(const std::vector<VkQueueFamilyProperties> &queue_family_properties);

        uint32_t Size() const { return queue_infos_.size(); }
        const QueueInfo & At(uint32_t index) const {
            return queue_infos_.at(index);
        }

        QueueInfo FirstOfType(VkQueueFlagBits bits) const;
    };
}