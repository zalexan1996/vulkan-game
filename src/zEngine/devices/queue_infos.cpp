#include "queue_infos.h"
#include "physical_device.h"
#include <stdexcept>
#include <algorithm>

namespace zEngine::devices
{
    QueueFamilyInfos::QueueFamilyInfos(const std::vector<QueueFamilyInfo> &queueInfos)
    {
        this->queueInfos = queueInfos;
    }

    QueueFamilyInfos::QueueFamilyInfos(const std::vector<VkQueueFamilyProperties> &properties)
    {
        std::transform(properties.begin(), properties.end(), std::back_inserter(queueInfos), [&properties](const VkQueueFamilyProperties & prop) {
            
            uint32_t index = &prop - &properties[0];
            return QueueFamilyInfo(index, prop.queueCount, prop.queueFlags);
        });
    }

    uint32_t QueueFamilyInfos::IndexOf(VkQueueFlagBits flagValue)
    {
        auto it = std::find_if(queueInfos.begin(), queueInfos.end(), [](const QueueFamilyInfo &info) {
            return info.isGraphics();
        });

        return it->Index;
    }
}