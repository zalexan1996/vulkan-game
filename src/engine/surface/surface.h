#pragma once
#include "engine/engine_vulkan.h"
#include <vector>

namespace engine
{
    class Surface
    {
        public:
            struct Capabilities {
                VkSurfaceCapabilitiesKHR capabilities_;
                std::vector<VkSurfaceFormatKHR> formats_;
                std::vector<VkPresentModeKHR> present_modes_;

                const VkFormat preferred_format_ = VkFormat::VK_FORMAT_B8G8R8A8_SRGB;
                const VkColorSpaceKHR preferred_color_space_ = VkColorSpaceKHR::VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
                const VkPresentModeKHR preferred_present_mode_ = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;

                VkSurfaceFormatKHR GetAvailableFormat() const;
            };

        private:
            VkSurfaceKHR surface_;
            VkInstance instance_;

        public:
            Surface(VkInstance instance, GLFWwindow *window);
            ~Surface();

            const VkSurfaceKHR& Vk() const {
                return surface_;
            }


            Capabilities GetCapabilities(VkPhysicalDevice physical_device) const;
    };
}