#include "renderer.h"

namespace engine::graphics
{
    Renderer::Renderer(VkDevice device, VkFormat format)
        : device_(device)
    {
        pipeline_ = std::make_unique<Pipeline>();
        render_pass_ = std::make_unique<RenderPass>(device);

        VkAttachmentDescription attachment{};
        attachment.format = format;
        attachment.samples = VK_SAMPLE_COUNT_1_BIT;
        attachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
        attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        attachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference attachmentRef{};
        attachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        attachmentRef.attachment = 0;

        VkSubpassDescription desc{};
        desc.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        desc.colorAttachmentCount = 1;
        desc.pColorAttachments = &attachmentRef;
        
        render_pass_->AddAttachment(attachment)
            .AddSubpass(desc)
            .Create();
    }
}