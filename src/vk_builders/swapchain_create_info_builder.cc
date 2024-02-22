#include "swapchain_create_info_builder.h"

namespace vk_builders
{

    SwapchainCreateInfoBuilder::SwapchainCreateInfoBuilder(uint32_t image_count)
    {
        info = {};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        info.clipped = VK_TRUE;
        info.compositeAlpha = VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        info.imageArrayLayers = 1;
        info.imageColorSpace = VkColorSpaceKHR::VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        info.imageFormat = VkFormat::VK_FORMAT_R8G8B8_SRGB;
        info.imageUsage = VkImageUsageFlagBits::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        info.minImageCount = image_count;
        info.presentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
        
    }

    SwapchainCreateInfoBuilder& SwapchainCreateInfoBuilder::AddSurface(VkSurfaceKHR surface, VkExtent2D surface_extent)
    {
        info.surface = surface;
        info.imageExtent = surface_extent;
        
        return *this;
    }

    SwapchainCreateInfoBuilder& SwapchainCreateInfoBuilder::QueueIndices(const std::vector<uint32_t> &presentation_queue_indices)
    {
        info.pQueueFamilyIndices = presentation_queue_indices.data();
        info.queueFamilyIndexCount = presentation_queue_indices.size();
        
        return *this;
    }
}