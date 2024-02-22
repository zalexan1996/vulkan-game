#pragma once
#include "engine/graphics/pipeline/pipeline.h"
#include "engine/graphics/render_pass/render_pass.h"
#include <memory>

namespace engine::graphics
{
    class Renderer
    {
        private:
            VkDevice device_;
            std::unique_ptr<Pipeline> pipeline_;
            std::unique_ptr<RenderPass> render_pass_;

        public:
            Renderer(VkDevice device, VkFormat format);
    };
}