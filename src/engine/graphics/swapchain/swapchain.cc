#include "swapchain.h"
#include "vk_builders/swapchain_create_info_builder.h"

namespace engine::graphics
{
    Swapchain::Swapchain(engine::devices::LogicalDevice* device, VkSurfaceKHR surface, VkExtent2D surface_extent)
    {
        auto queue_indices = device->GetPresentationQueues();
        auto info = vk_builders::SwapchainCreateInfoBuilder(2)
            .AddSurface(surface, surface_extent)
            .QueueIndices(queue_indices)
            .Build();

        vkCreateSwapchainKHR(device->Vk(), &info, nullptr, &swapchain_);
    }
}