#pragma once
#include "engine/engine_vulkan.h"
#include <vector>

namespace engine::graphics
{
    class RenderPass
    {
        private:
            std::vector<VkAttachmentDescription> attachments_;
            std::vector<VkSubpassDescription> subpasses_;
            std::vector<VkSubpassDependency> dependencies_;

            VkRenderPass render_pass_ = nullptr;
            VkDevice device_;

        public:
            RenderPass(VkDevice device);
            ~RenderPass();
            
            RenderPass& AddAttachment(VkAttachmentDescription desc);
            RenderPass& AddSubpass(VkSubpassDescription desc);
            RenderPass& AddDependency(VkSubpassDependency dep);

            VkResult Create();
    };
}