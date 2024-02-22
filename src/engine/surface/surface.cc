#include "surface.h"
#include <algorithm>

namespace engine
{

    VkSurfaceFormatKHR Surface::Capabilities::GetAvailableFormat() const
    {
        const auto &it = std::find_if(formats_.begin(), formats_.end(), [&](const VkSurfaceFormatKHR &f) {
            return f.colorSpace == preferred_color_space_ && f.format == preferred_format_;
        });
        
        if (it == formats_.end())
        {
            return formats_.at(0);
        }

        return *it;
    }

    Surface::Surface(VkInstance instance, GLFWwindow*window)
        : instance_(instance)
    {
        glfwCreateWindowSurface(instance, window, nullptr, &surface_);
    }

    Surface::~Surface()
    {
        if (surface_ != nullptr)
        {
            vkDestroySurfaceKHR(instance_, surface_, nullptr);
        }
    }

    Surface::Capabilities Surface::GetCapabilities(VkPhysicalDevice physical_device) const
    {
        uint32_t count;
        Surface::Capabilities capabilities{};
        vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical_device, surface_, &capabilities.capabilities_);


        vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface_, &count, nullptr);
        capabilities.formats_.resize(count);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physical_device, surface_, &count, capabilities.formats_.data());

        vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface_, &count, nullptr);
        capabilities.present_modes_.resize(count);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physical_device, surface_, &count, capabilities.present_modes_.data());

        return capabilities;
    }
}