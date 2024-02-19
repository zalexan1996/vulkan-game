#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

class GLFWwindow;

namespace zEngine
{
    class Window
    {
        public:
            Window(int width, int height, const std::string& windowName);
            Window(const Window&) = delete;
            ~Window();

            bool shouldClose();

            void Poll();
            void CreateSurface(VkInstance instance);
            VkSurfaceKHR GetSurface() const { return vkSurface; }
        private:
            GLFWwindow *window;
            VkSurfaceKHR vkSurface;
    };
}