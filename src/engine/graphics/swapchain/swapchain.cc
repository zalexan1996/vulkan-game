#include "swapchain.h"
#include "vk_builders/swapchain_create_info_builder.h"
#include <algorithm>
#include "common/asserts.h"

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

        common::Assert::VulkanSuccess(vkCreateSwapchainKHR(device->Vk(), &info, nullptr, &swapchain_), "Failed to create swapchain.");

        format_ = info.imageFormat;
        extent_ = info.imageExtent;

        BuildImages();
    }

    Swapchain::~Swapchain()
    {
        images_.clear();
        if (swapchain_ != nullptr)
        {
            vkDestroySwapchainKHR(device_, swapchain_, nullptr);
        }
    }

    void Swapchain::BuildImages()
    {
        uint32_t count;
        vkGetSwapchainImagesKHR(device_, swapchain_, &count, nullptr);
        std::vector<VkImage> images(count);
        images_.resize(count);
        vkGetSwapchainImagesKHR(device_, swapchain_, &count, images.data());

        for(size_t i = 0; i < count; i++) {
            images_.push_back(std::make_shared<SwapchainImage>(device_, swapchain_, format_, images.at(i)));
        }
    }
}