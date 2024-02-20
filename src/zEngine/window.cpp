#include "window.h"
#include "application.h"
#include "asserts.h"
#include <vector>
#include <algorithm>

namespace zEngine
{
    
    Window::Window(int width, int height, const std::string& windowName)
    {
        
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }

    Window::~Window()
    {
        if (vkSurface != nullptr)
        {
            vkDestroySurfaceKHR(Application::GetVkInstance(), vkSurface, nullptr);
        }
        
        if (window != nullptr)
        {
            glfwDestroyWindow(window);
            window = nullptr;
        }
        glfwTerminate();
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(window);
    }

    void Window::Poll()
    {
        glfwPollEvents();
    }

    void Window::CreateSurface(VkInstance instance)
    {
        auto result = glfwCreateWindowSurface(instance, window, nullptr, &vkSurface);

        common::Assert::VulkanSuccess(result, "Failed to create window surface.");
    }

    common::SurfaceProperties Window::GetSurfaceCapabilities(VkPhysicalDevice d)
    {
        return common::SurfaceProperties(d, GetSurface());
    }
    VkExtent2D Window::GetFramebufferSize(const VkSurfaceCapabilitiesKHR& capabilities) const
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        return {
            std::clamp((uint32_t)width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width),
            std::clamp((uint32_t)height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height)
        };
    }

} // namespace zEngine
