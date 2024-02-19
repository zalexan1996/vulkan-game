#pragma once
#include "physical_device.h"

namespace zEngine::devices
{
    class LogicalDevice
    {
        private:
            VkDevice vkDevice;
            
        public:
            LogicalDevice(const PhysicalDevice &d);
            ~LogicalDevice();
    };
}