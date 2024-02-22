#include "queue_container.h"
#include <algorithm>
#include <stdexcept>

namespace engine::devices
{
    QueueContainer::QueueContainer(VkDevice device)
        : device_(device)
    {
        
    }

    QueueContainer::~QueueContainer()
    {
        
    }

    void QueueContainer::Register(const QueueInfo& queue_info, VkQueue queue)
    {
        queue_data_.push_back(QueueData(queue_info, queue));
    }

    QueueContainer::QueueData &QueueContainer::GetAvailable(VkQueueFlagBits queue_type)
    {
        auto queue_data_it = std::find_if(queue_data_.begin(), queue_data_.end(), [&queue_type](const QueueData&data) {
            return data.queue_info_.flags_ & queue_type;
        });

        if (queue_data_it == queue_data_.end())
        {
            throw std::runtime_error("There wasnt a queue registered with the requested type.");
        }

        return *queue_data_it;
    }
}