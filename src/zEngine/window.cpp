#include "window.h"
#include "application.h"
#include "asserts.h"

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

} // namespace zEngine
