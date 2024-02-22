#include "swapchain_image.h"
#include "vk_builders/image_view_create_info_builder.h"
#include "common/asserts.h"

namespace engine::graphics
{

    SwapchainImage::SwapchainImage(VkDevice device, VkSwapchainKHR swapchain, VkFormat format, VkImage image)
        : device_(device)
    {
        auto create_info = vk_builders::ImageViewCreateInfoBuilder(format, image)
            .Build();

        common::Assert::VulkanSuccess(vkCreateImageView(device, &create_info, nullptr, &image_view_), "Failed to create image view.");
    }

    SwapchainImage::~SwapchainImage()
    {
        if (image_view_ != nullptr)
        {
            vkDestroyImageView(device_, image_view_, nullptr);
        }

        if (image_ != nullptr)
        {
            vkDestroyImage(device_, image_, nullptr);
        }
    }
}