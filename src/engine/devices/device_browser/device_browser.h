#pragma once
#include "engine/devices/physical_device/physical_device.h"
#include "engine/instance/instance.h"
#include "engine/devices/device_requirement.h"

namespace engine::devices
{
    class DeviceBrowser
    {
        public:
            DeviceBrowser(const Instance *instance);
            PhysicalDevice First(const DeviceRequirement &requirement = DeviceRequirement()) const;
            PhysicalDevice Best(const DeviceRequirement &requirement = DeviceRequirement()) const;

            std::vector<VkPhysicalDevice> EnumerateDevices() const;
            bool IsDeviceSupported(const VkPhysicalDevice& d, const DeviceRequirement &requirement) const;

        private:
            const Instance *instance_;
    };
}