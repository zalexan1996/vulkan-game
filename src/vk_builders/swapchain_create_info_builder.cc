#include "swapchain_create_info_builder.h"
#include <algorithm>

namespace vk_builders
{

    SwapchainCreateInfoBuilder::SwapchainCreateInfoBuilder(const engine::Surface::Capabilities &capabilities, VkSurfaceKHR surface)
    {
        const auto format = capabilities.GetAvailableFormat();

        info = {};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        info.clipped = VK_TRUE;
        info.compositeAlpha = VkCompositeAlphaFlagBitsKHR::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        info.imageArrayLayers = 1;
        info.imageUsage = VkImageUsageFlagBits::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        info.minImageCount = capabilities.capabilities_.minImageCount + 1;
        info.presentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
        info.surface = surface;
        info.preTransform = capabilities.capabilities_.currentTransform;
        info.imageColorSpace = format.colorSpace;
        info.imageFormat = format.format;
        info.imageExtent = VkExtent2D(
            std::clamp(capabilities.capabilities_.currentExtent.width, capabilities.capabilities_.minImageExtent.width, capabilities.capabilities_.maxImageExtent.width),
            std::clamp(capabilities.capabilities_.currentExtent.height, capabilities.capabilities_.minImageExtent.height, capabilities.capabilities_.maxImageExtent.height)
        );
    }

    SwapchainCreateInfoBuilder& SwapchainCreateInfoBuilder::QueueIndices(const std::vector<uint32_t> &presentation_queue_indices)
    {
        info.pQueueFamilyIndices = presentation_queue_indices.data();
        info.queueFamilyIndexCount = presentation_queue_indices.size();
        
        return *this;
    }
}