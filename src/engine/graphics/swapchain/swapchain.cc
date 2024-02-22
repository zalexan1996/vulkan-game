#include "swapchain.h"
#include "vk_builders/swapchain_create_info_builder.h"
#include <algorithm>

namespace engine::graphics
{
    Swapchain::Swapchain(engine::devices::LogicalDevice* device, engine::Surface* surface)
        : device_(device->Vk())
    {
        auto queue_indices = device->GetPresentationQueues();
        auto cap = surface->GetCapabilities(device->GetPhysicalDevice().Vk());

        auto info = vk_builders::SwapchainCreateInfoBuilder(cap, surface->Vk())
            .QueueIndices(queue_indices)
            .Build();

        vkCreateSwapchainKHR(device->Vk(), &info, nullptr, &swapchain_);
    }

    Swapchain::~Swapchain()
    {
        if (swapchain_ != nullptr)
        {
            vkDestroySwapchainKHR(device_, swapchain_, nullptr);
        }
    }
}