#pragma once
#include "vk_builder.h"
#include "engine/engine_vulkan.h"

namespace vk_builders
{
    class ImageViewCreateInfoBuilder : VkBuilder<VkImageViewCreateInfo>
    {
        private:
            VkImageViewCreateInfo info;

        public:
            ImageViewCreateInfoBuilder(VkFormat format, VkImage image);
            VkImageViewCreateInfo& Build() {
                return info;
            }
    };
}