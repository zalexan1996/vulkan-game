#pragma once
#include "engine/devices/physical_device/physical_device.h"
#include "common/config/configuration.h"

namespace engine::devices
{
    class LogicalDevice
    {
        private:
            PhysicalDevice physical_device_;
            VkDevice logical_device_ = nullptr;
            VkQueue queue;
            
        public:
            LogicalDevice(const PhysicalDevice &physical_device, const common::config::Configuration &config);
            ~LogicalDevice();
            
            const PhysicalDevice &GetPhysicalDevice() const {
                return physical_device_;
            }

            const VkDevice& Vk() const {
                return logical_device_;
            }
    };
}