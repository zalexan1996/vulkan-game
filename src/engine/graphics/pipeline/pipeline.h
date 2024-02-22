#pragma once
#include "engine/engine_vulkan.h"

namespace engine::graphics
{
    class Pipeline
    {
        private:
            VkPipeline pipeline_;

        public:
            Pipeline();
    };
}