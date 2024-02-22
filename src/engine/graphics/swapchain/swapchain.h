#pragma once
#include "engine/engine_vulkan.h"
#include "engine/devices/logical_device/logical_device.h"
#include "engine/surface/surface.h"
#include "swapchain_image.h"
#include <memory>

namespace engine::graphics
{
    class Swapchain
    {
        private:
            VkSwapchainKHR swapchain_;
            VkDevice device_;
            std::vector<std::shared_ptr<SwapchainImage>> images_;
            VkExtent2D extent_;
            VkFormat format_;

        protected:
            void BuildImages();
            
        public:
            Swapchain(engine::devices::LogicalDevice *device, engine::Surface* surface);
            ~Swapchain();

            const VkFormat &Format() const {
                return format_;
            }
            const VkExtent2D &Extent() const {
                return extent_;
            }
    };
}