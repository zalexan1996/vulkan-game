#include "image_view_create_info_builder.h"

namespace vk_builders
{

    ImageViewCreateInfoBuilder::ImageViewCreateInfoBuilder(VkFormat format, VkImage image)
    {
        info = {};
        info.components = {};
        info.format = format;
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        info.subresourceRange.aspectMask = VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT;
        info.subresourceRange.baseArrayLayer = 0;
        info.subresourceRange.baseMipLevel = 0;
        info.subresourceRange.layerCount = 1;
        info.subresourceRange.levelCount = 1;
        info.viewType = VkImageViewType::VK_IMAGE_VIEW_TYPE_2D;
        info.image = image;
    }
}