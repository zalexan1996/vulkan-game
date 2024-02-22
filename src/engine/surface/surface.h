#pragma once
#include "engine/engine_vulkan.h"

namespace engine
{
    class Surface
    {
        private:
            VkSurfaceKHR surface_;
            VkInstance instance_;
        public:
            Surface(VkInstance instance, GLFWwindow *window);
            ~Surface();

            const VkSurfaceKHR& Vk() const {
                return surface_;
            }
    };
}