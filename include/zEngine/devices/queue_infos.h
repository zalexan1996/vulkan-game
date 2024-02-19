#pragma once
#include <vector>
#include <vulkan/vulkan.h>

namespace zEngine::devices
{
    struct QueueFamilyInfo
    {
        QueueFamilyInfo() 
            : Index(0), Count(0), Flags(0) { }

        QueueFamilyInfo(uint32_t index, uint32_t count, uint32_t flags)
            : Index(index), Count(count), Flags(flags) { }
            
        uint32_t Index;
        uint32_t Count;
        uint32_t Flags;

        constexpr bool isGraphics() const { return Flags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT; }
        constexpr bool isCompute() const { return Flags & VkQueueFlagBits::VK_QUEUE_COMPUTE_BIT; }
        constexpr bool isTransfer() const { return Flags & VkQueueFlagBits::VK_QUEUE_TRANSFER_BIT; }

        QueueFamilyInfo& operator=(const QueueFamilyInfo & info)
        {
            Index = info.Index;
            Count = info.Count;
            Flags = info.Flags;
            return *this;
        }
    };

    class QueueFamilyInfos
    {
        private:
            std::vector<QueueFamilyInfo> queueInfos;

        public:
            QueueFamilyInfos() {}
            QueueFamilyInfos(const std::vector<QueueFamilyInfo> &queueInfos);
            QueueFamilyInfos(const std::vector<VkQueueFamilyProperties> &properties);
            uint32_t IndexOf(VkQueueFlagBits flagValue);
    };
}