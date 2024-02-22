#pragma once
#include "engine/engine_vulkan.h"
#include "engine/devices/logical_device/logical_device.h"
#include "engine/surface/surface.h"

namespace engine::graphics
{
    class Swapchain
    {
        private:
            VkSwapchainKHR swapchain_;
            VkDevice device_;

        public:
            Swapchain(engine::devices::LogicalDevice *device, engine::Surface* surface);
            ~Swapchain();
    };
}