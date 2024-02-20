#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>
#include "surface_properties.h"

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

            common::SurfaceProperties GetSurfaceCapabilities(VkPhysicalDevice d);
            VkExtent2D GetFramebufferSize(const VkSurfaceCapabilitiesKHR& capabilities) const;
        private:
            GLFWwindow *window;
            VkSurfaceKHR vkSurface;
    };
}