#include "window.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

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
        glfwDestroyWindow(window);
        window = nullptr;
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

} // namespace zEngine
