#include "surface.h"

namespace engine
{

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
}