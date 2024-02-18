#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace zEngine::common
{
    class Assert
    {
        public:
            Assert() = delete;
            static void VulkanSuccess(VkResult result, const std::string& message);
    };
}