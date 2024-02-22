#include "queue_info.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

namespace engine::devices
{
    QueueInfo::QueueInfo(uint32_t index, uint32_t flags, uint32_t count)
        : index_(index), flags_(flags), count_(count)
    { }

    void QueueInfo::Print() const
    {
        std::cout << std::setw(12) << index_
            << std::setw(12) << count_ 
            << std::setw(12) << SupportsCompute() 
            << std::setw(12) << SupportsGraphics()
            << std::setw(12) << SupportsTransfer() 
            << std::endl;
    }

    QueueInfos::QueueInfos(const std::vector<VkQueueFamilyProperties> &queue_family_properties)
    {
        queue_infos_.resize(queue_family_properties.size());

        uint32_t index = 0;
        std::transform(queue_family_properties.begin(), queue_family_properties.end(), queue_infos_.begin(), [&index](const VkQueueFamilyProperties &prop) {
            return QueueInfo(index++, prop.queueFlags, prop.queueCount);
        });
    }

    QueueInfo QueueInfos::FirstOfType(VkQueueFlagBits bits) const
    {
        auto info_it = std::find_if(queue_infos_.begin(), queue_infos_.end(), [&bits](const QueueInfo&info) {
            return info.flags_ & bits;
        });

        if (info_it == queue_infos_.end())
        {
            throw std::runtime_error("There were no queue families that support: " + std::to_string(bits));
        }

        return *info_it;
    }
}