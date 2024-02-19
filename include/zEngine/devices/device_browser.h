#pragma once
#include <vulkan/vulkan.h>

namespace zEngine::devices
{
    class DeviceBrowser
    {
        public:
            VkPhysicalDevice FindBest();
            bool isSupported(VkPhysicalDevice d);
    };
}