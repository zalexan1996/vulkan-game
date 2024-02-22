#include "device_browser.h"
#include "engine/engine_vulkan.h"
#include <algorithm>
#include <stdexcept>

namespace engine::devices
{
    DeviceBrowser::DeviceBrowser(const Instance *instance)
        : instance_(instance) { }

    PhysicalDevice DeviceBrowser::First(const DeviceRequirement &requirement) const
    {
        const auto devices = EnumerateDevices();
        auto device_it = std::find_if(devices.begin(), devices.end(), [&](const VkPhysicalDevice &d) {
            return this->IsDeviceSupported(d, requirement);
        });

        if (device_it == devices.end())
        {
            throw std::runtime_error("None of the graphics cards are supported.");
        }

        return PhysicalDevice(*device_it);
    }

    PhysicalDevice DeviceBrowser::Best(const DeviceRequirement &requirement) const
    {
        return First(requirement);
    }

    std::vector<VkPhysicalDevice> DeviceBrowser::EnumerateDevices() const
    {
        uint32_t count;
        vkEnumeratePhysicalDevices(instance_->Vk(), &count, nullptr);
        std::vector<VkPhysicalDevice> devices(count);
        vkEnumeratePhysicalDevices(instance_->Vk(), &count, devices.data());

        return devices;
    }

    bool DeviceBrowser::IsDeviceSupported(const VkPhysicalDevice& d, const DeviceRequirement &requirement) const
    {
        VkPhysicalDeviceProperties prop;
        vkGetPhysicalDeviceProperties(d, &prop);

        bool supports_vulkan = prop.apiVersion >= requirement.vulkan_version;
        bool is_required_type = prop.deviceType == requirement.device_type;
        return supports_vulkan && is_required_type;
    }
}