#include "device_create_info_builder.h"

namespace vk_builders
{
    DeviceQueueCreateInfoBuilder::DeviceQueueCreateInfoBuilder(uint32_t index, uint32_t count, const float *priorities)
    {
        info = {};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        info.queueFamilyIndex = index;
        info.queueCount = count;
        info.pQueuePriorities = priorities;
    }

    DeviceCreateInfoBuilder::DeviceCreateInfoBuilder()
    {
        info = {};
        info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    }

    DeviceCreateInfoBuilder& DeviceCreateInfoBuilder::AddExtensions(const std::vector<const char*> &extensions)
    {
        info.enabledExtensionCount = extensions.size();
        info.ppEnabledExtensionNames = extensions.data();
        return *this;
    }

    DeviceCreateInfoBuilder& DeviceCreateInfoBuilder::AddQueue(const std::vector<VkDeviceQueueCreateInfo> &queueInfos)
    {
        info.pQueueCreateInfos = queueInfos.data();
        info.queueCreateInfoCount = queueInfos.size();
        return *this;
    }

    DeviceCreateInfoBuilder& DeviceCreateInfoBuilder::AddQueue(const VkDeviceQueueCreateInfo &queueInfos)
    {
        info.pQueueCreateInfos = &queueInfos;
        info.queueCreateInfoCount = 1;
        return *this;
    }
}