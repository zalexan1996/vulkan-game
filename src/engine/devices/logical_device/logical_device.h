#pragma once
#include "engine/devices/physical_device/physical_device.h"
#include "common/config/configuration.h"
#include "engine/devices/queue_container/queue_container.h"
#include <memory>
#include "engine/commands/command_pool/command_pool.h"
#include <map>
namespace engine::devices
{
    class LogicalDevice
    {
        private:
            PhysicalDevice physical_device_;
            VkDevice logical_device_ = nullptr;
            std::unique_ptr<QueueContainer> queue_container_;
            std::map<uint32_t, std::unique_ptr<engine::commands::CommandPool>> command_pools_;
            
        protected:
            void CreateQueueContainer();
            void CreateCommandPool();
        public:
            LogicalDevice(const PhysicalDevice &physical_device, const common::config::Configuration &config);
            ~LogicalDevice();
            
            PhysicalDevice GetPhysicalDevice() const {
                return physical_device_;
            }

            VkDevice Vk() const {
                return logical_device_;
            }

            std::vector<uint32_t> GetPresentationQueues() const;
    };
}