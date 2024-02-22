#pragma once
#include "engine/engine_vulkan.h"

namespace engine::commands
{
    class CommandPool
    {
        private:
            VkDevice device_;
            VkCommandPool pool_;

        public:
            CommandPool(VkDevice device, uint32_t queue_family_index);
            ~CommandPool();
    };
}