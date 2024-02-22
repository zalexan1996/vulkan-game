#pragma once
#include "engine/devices/device_queue/queue_info.h"

namespace engine::devices
{
    class QueueContainer
    {
        protected:
            struct QueueData
            {
                QueueData(const QueueInfo& queue_info, VkQueue queue)
                    : queue_info_(queue_info), queue_(queue)
                { }

                QueueInfo queue_info_;
                VkQueue queue_;

                enum QueueStatus {
                    Available,
                    InUse
                } queue_status_ = Available;
            };

        private:
            std::vector<QueueData> queue_data_{};
            VkDevice device_;

        public:
            QueueContainer(VkDevice device);
            ~QueueContainer();

            void Register(const QueueInfo& queueInfo, VkQueue queue);
            QueueData &GetAvailable(VkQueueFlagBits queueType);
    };
}