#pragma once
#include "engine/engine_vulkan.h"

namespace engine::graphics
{
    class SwapchainImage
    {
        private:
            VkImageView image_view_ = nullptr;
            VkImage image_ = nullptr;
            VkDevice device_ = nullptr;

        public:
            SwapchainImage() {}
            SwapchainImage(VkDevice device, VkSwapchainKHR swapchain, VkFormat format, VkImage image);
            ~SwapchainImage();
    };
}