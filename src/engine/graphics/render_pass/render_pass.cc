#include "render_pass.h"

namespace engine::graphics
{
    RenderPass::RenderPass(VkDevice device)
        : device_(device)
    {
        
    }

    RenderPass::~RenderPass()
    {
        if (render_pass_ != nullptr)
        {
            vkDestroyRenderPass(device_, render_pass_, nullptr);
        }
    }

    RenderPass& RenderPass::AddAttachment(VkAttachmentDescription desc)
    {
        attachments_.push_back(desc);
        return *this;
    }
    
    RenderPass& RenderPass::AddSubpass(VkSubpassDescription desc)
    {
        subpasses_.push_back(desc);
        return *this;
    }
    
    RenderPass& RenderPass::AddDependency(VkSubpassDependency dep)
    {
        dependencies_.push_back(dep);
        return *this;
    }

    VkResult RenderPass::Create()
    {
        VkRenderPassCreateInfo create_info{};
        create_info.sType = VkStructureType::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        create_info.attachmentCount = attachments_.size();
        create_info.dependencyCount = dependencies_.size();
        create_info.pAttachments = attachments_.data();
        create_info.pDependencies = dependencies_.data();
        create_info.pSubpasses = subpasses_.data();
        create_info.subpassCount = subpasses_.size();

        return vkCreateRenderPass(device_, &create_info, nullptr, &render_pass_);
    }
}