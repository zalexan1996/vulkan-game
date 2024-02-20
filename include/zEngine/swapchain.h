#pragma once
#include <vulkan/vulkan.h>
#include <memory>
#include "logical_device.h"

namespace zEngine
{
    class Swapchain
    {
        public:
            VkSwapchainKHR swapchain;
            Swapchain(const devices::LogicalDevice * device);
    };
}