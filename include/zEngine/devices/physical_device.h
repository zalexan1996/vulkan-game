#pragma once
#include "queue_infos.h"

namespace zEngine::devices
{
    class PhysicalDevice
    {
        private:
            VkPhysicalDevice vkPhysicalDevice;

        public:
            PhysicalDevice(VkPhysicalDevice vkDevice);
            VkPhysicalDeviceProperties GetProperties() const;
            const QueueFamilyInfos GetQueueFamilyInfos() const;
            const VkPhysicalDeviceFeatures GetFeatures() const;
            constexpr VkPhysicalDevice GetVkPhysicalDevice() const { return vkPhysicalDevice; }

            void Print() const;
    };
}