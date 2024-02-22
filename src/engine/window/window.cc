#include "window.h"
#include <memory>
#include <algorithm>
#include "common/asserts.h"

namespace engine
{
    Window::Window(const common::config::Configuration &config)
    {
        window = CreateWindow(config);
    }

    void Window::InitGlfw()
    {
        if (glfwInit() == GLFW_FALSE)
        {
            throw new std::runtime_error("GLFW failed to initialize.");
        }
    }
    
    GLFWwindow *Window::CreateWindow(const common::config::Configuration &config)
    {
        const bool& fullscreen = config.user_settings_.display_settings_.fullscreen;
        const int& width = config.user_settings_.display_settings_.window_width;
        const int& height = config.user_settings_.display_settings_.window_height;
        const char * title = config.vulkan_settings_.window_title;

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        auto monitor = fullscreen ? glfwGetPrimaryMonitor() : nullptr;

        return glfwCreateWindow(width, height, title, monitor, nullptr);
    }

    Window::~Window()
    {
        if (window != nullptr)
        {
            glfwDestroyWindow(window);
        }

        glfwTerminate();
    }

    void Window::Poll()
    {
        glfwPollEvents();
    }
    
    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(window);
    }
}