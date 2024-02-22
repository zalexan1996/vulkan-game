#pragma once
#include "vk_builder.h"
#include "engine/engine_vulkan.h"
#include <string>
#include <vector>

namespace vk_builders
{
    class SwapchainCreateInfoBuilder : VkBuilder<VkSwapchainCreateInfoKHR>
    {
        private:
            VkSwapchainCreateInfoKHR info;
        public:
            SwapchainCreateInfoBuilder(uint32_t image_count = 1);

            SwapchainCreateInfoBuilder& AddSurface(VkSurfaceKHR surface, VkExtent2D surface_extent);

            SwapchainCreateInfoBuilder& QueueIndices(const std::vector<uint32_t> &presentation_queue_indices);

            VkSwapchainCreateInfoKHR &Build() {
                return info;
            }

    };
}