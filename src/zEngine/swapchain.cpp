#include "swapchain.h"
#include "application.h"
#include "window.h"

namespace zEngine
{
    Swapchain::Swapchain(const devices::LogicalDevice * device)
    {
        const auto & window = Application::GetSingleton()->window;
        const auto capabilities = window->GetSurfaceCapabilities(device->GetVkPhysicalDevice());
        VkSwapchainCreateInfoKHR createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
        createInfo.imageColorSpace = VkColorSpaceKHR::VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        createInfo.imageFormat = VkFormat::VK_FORMAT_B8G8R8_SRGB;
        createInfo.presentMode = VkPresentModeKHR::VK_PRESENT_MODE_FIFO_KHR;
        createInfo.surface = window->GetSurface();
        createInfo.minImageCount = capabilities.Capabilities.minImageCount + 1;
        
        vkCreateSwapchainKHR(device->GetDevice(), &createInfo, nullptr, &swapchain);
    }
}