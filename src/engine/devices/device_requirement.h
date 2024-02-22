#pragma once
#include <vector>
#include "engine/engine_vulkan.h"
namespace engine::devices
{
    struct DeviceRequirement
    {
        const std::vector<const char*> RequiredExtensions;
        bool graphics_family = true;
        bool compute_family = true;
        bool transfer_family = true;
        bool presentation = true;
        uint32_t vulkan_version = VK_API_VERSION_1_3;
        VkPhysicalDeviceType device_type = VkPhysicalDeviceType::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU;
    };
}