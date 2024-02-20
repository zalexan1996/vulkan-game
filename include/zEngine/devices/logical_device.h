#pragma once
#include "physical_device.h"

namespace zEngine::devices
{
    class LogicalDevice
    {
        private:
            VkDevice vkDevice;
            PhysicalDevice physicalDevice;
            VkQueue queue;

        public:
            LogicalDevice(const PhysicalDevice &d);
            ~LogicalDevice();
            VkQueue GetQueue(VkQueueFlagBits queueType);
            VkDevice GetDevice() const { return vkDevice; }
            VkPhysicalDevice GetVkPhysicalDevice() const { return physicalDevice.GetVkPhysicalDevice(); }
    };
}