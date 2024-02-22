#pragma once
#include "vk_builder.h"
#include "engine/engine_vulkan.h"
#include <string>
#include <vector>
#include "engine/surface/surface.h"

namespace vk_builders
{
    class SwapchainCreateInfoBuilder : VkBuilder<VkSwapchainCreateInfoKHR>
    {
        private:
            VkSwapchainCreateInfoKHR info;

        public:
            SwapchainCreateInfoBuilder(const engine::Surface::Capabilities &capabilities, VkSurfaceKHR surface);

            SwapchainCreateInfoBuilder& QueueIndices(const std::vector<uint32_t> &presentation_queue_indices);

            VkSwapchainCreateInfoKHR &Build() {
                return info;
            }

    };
}