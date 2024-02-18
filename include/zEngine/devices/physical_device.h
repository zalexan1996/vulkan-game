#pragma once
#include <vulkan/vulkan.h>

namespace zEngine::devices
{
    struct QueueFamilyCounts
    {
        unsigned short graphics = 0;
        unsigned short compute = 0;
        unsigned short transfer = 0;
    };

    class PhysicalDevice
    {
        private:
            VkPhysicalDevice vkPhysicalDevice;
            QueueFamilyCounts queueFamilyCounts;

        public:
            PhysicalDevice(VkPhysicalDevice vkDevice);
            VkPhysicalDeviceProperties GetProperties();
            const QueueFamilyCounts& GetQueueFamilyCounts();
    };
}