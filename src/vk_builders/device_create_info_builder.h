#pragma once
#include "vk_builder.h"
#include "engine/engine_vulkan.h"
#include <vector>

namespace vk_builders
{
    class DeviceQueueCreateInfoBuilder : VkBuilder<VkDeviceQueueCreateInfo>
    {
        private:
            VkDeviceQueueCreateInfo info;

        public:
            DeviceQueueCreateInfoBuilder(uint32_t index, uint32_t count, const float *priorities);

            const VkDeviceQueueCreateInfo &Build() {
                return info;
            }
    };

    class DeviceCreateInfoBuilder : VkBuilder<VkDeviceCreateInfo>
    {
        private:
            VkDeviceCreateInfo info;

        public:
            DeviceCreateInfoBuilder();

            DeviceCreateInfoBuilder& AddExtensions(const std::vector<const char*> &extensions);
            DeviceCreateInfoBuilder& AddQueue(const std::vector<VkDeviceQueueCreateInfo> &queueInfos);
            DeviceCreateInfoBuilder& AddQueue(const VkDeviceQueueCreateInfo &queueInfos);

            const VkDeviceCreateInfo &Build() {
                return info;
            }
    };
}