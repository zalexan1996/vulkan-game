#pragma once
#include "queue_infos.h"

namespace zEngine::devices
{
    class PhysicalDevice
    {
        private:
            VkPhysicalDevice vkPhysicalDevice;
            QueueFamilyInfos queueFamilyInfos;

        public:
            PhysicalDevice(VkPhysicalDevice vkDevice);
            PhysicalDevice(const PhysicalDevice &physicalDevice);
            
            VkPhysicalDeviceProperties GetProperties() const;
            const QueueFamilyInfos &GetQueueFamilyInfos() const { return queueFamilyInfos; }
            const VkPhysicalDeviceFeatures GetFeatures() const;
            constexpr VkPhysicalDevice GetVkPhysicalDevice() const { return vkPhysicalDevice; }

            void Print() const;
    };
}