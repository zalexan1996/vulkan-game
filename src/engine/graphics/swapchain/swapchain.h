#pragma once
#include "engine/engine_vulkan.h"
#include "engine/devices/logical_device/logical_device.h"

namespace engine::graphics
{
    class Swapchain
    {
        private:
            VkSwapchainKHR swapchain_;

        public:
            Swapchain(engine::devices::LogicalDevice *device, VkSurfaceKHR surface, VkExtent2D surface_extent);
    };
}