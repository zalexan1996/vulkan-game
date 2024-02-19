#include "queue_infos.h"
#include "physical_device.h"
#include <stdexcept>
#include <algorithm>
#include "application.h"
#include <iostream>

namespace zEngine::devices
{
    QueueFamilyInfos::QueueFamilyInfos(const std::vector<QueueFamilyInfo> &queueInfos)
    {
        this->queueInfos = queueInfos;
    }

    QueueFamilyInfos::QueueFamilyInfos(const std::vector<VkQueueFamilyProperties> &properties, VkPhysicalDevice device)
    {
        std::transform(properties.begin(), properties.end(), std::back_inserter(queueInfos), [&properties](const VkQueueFamilyProperties & prop) {
            
            uint32_t index = &prop - &properties[0];
            return QueueFamilyInfo(index, prop.queueCount, prop.queueFlags);
        });


        auto surface = Application::GetSurface();

        std::erase_if(queueInfos, [&device, &surface](const QueueFamilyInfo & info) {
            if (info.isGraphics()) {
                VkBool32 presentationSupported;
                vkGetPhysicalDeviceSurfaceSupportKHR(device, info.Index, surface, &presentationSupported);
                return !presentationSupported;
            }

            return false;
        });
    }

    uint32_t QueueFamilyInfos::IndexOf(VkQueueFlagBits flagValue)
    {
        auto it = std::find_if(queueInfos.begin(), queueInfos.end(), [&flagValue](const QueueFamilyInfo &info) {
            return info.Flags & flagValue;
        });

        if (it == queueInfos.end())
        {
            throw std::runtime_error("No queues exist on device.");
        }

        return it->Index;
    }
}