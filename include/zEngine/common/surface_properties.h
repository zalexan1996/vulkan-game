#pragma once
#include <vulkan/vulkan.h>
#include <vector>
namespace zEngine::common
{
    struct SurfaceProperties
    {
        SurfaceProperties(VkPhysicalDevice device, VkSurfaceKHR surface)
        {
            uint32_t count;
            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &Capabilities);

            vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &count, nullptr);
            Formats.resize(count);
            vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &count, Formats.data());

            vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &count, nullptr);
            PresentModes.resize(count);
            vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &count, PresentModes.data());
        }

        VkSurfaceCapabilitiesKHR Capabilities;
        std::vector<VkSurfaceFormatKHR> Formats;
        std::vector<VkPresentModeKHR> PresentModes;

        bool IsSupported()
        {
            return !Formats.empty() && !PresentModes.empty();
        }
    };
}