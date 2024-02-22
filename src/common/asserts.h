#pragma once
#include <stdexcept>
#include <vulkan/vulkan.h>

namespace common
{
    class Assert
    {
        public:
            static void VulkanSuccess(VkResult result, const std::string& message);
    };
}