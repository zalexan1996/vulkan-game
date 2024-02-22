#pragma once
#include "engine/engine_vulkan.h"
#include <string>
#include <vector>
#include "engine/devices/device_queue/queue_info.h"

namespace engine::devices
{
    class PhysicalDevice
    {
        private:
            VkPhysicalDevice physical_device_;
            std::string VersionToString(uint32_t vesion) const;

        public:
            PhysicalDevice(VkPhysicalDevice physical_device);
            ~PhysicalDevice();
            VkPhysicalDeviceProperties GetProperties() const;
            VkPhysicalDeviceFeatures GetFeatures() const;
            QueueInfos GetQueues() const;
            
            void Print() const;
            const VkPhysicalDevice &Vk() const { return physical_device_; }

    };
}