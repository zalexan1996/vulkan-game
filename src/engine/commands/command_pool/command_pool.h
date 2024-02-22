#pragma once
#include "engine/engine_vulkan.h"
#include <vector>

namespace engine::commands
{
    class CommandPool
    {
        private:
            VkDevice device_;
            VkCommandPool pool_;
            std::vector<VkCommandBuffer> buffers_;

        public:
            CommandPool(VkDevice device, uint32_t queue_family_index);
            ~CommandPool();

            void Allocate(uint32_t count);
    };
}