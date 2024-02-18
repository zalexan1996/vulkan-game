#include "application.h"
#include "window.h"
#include "app_settings.h"
#include "device_browser.h"
#include "asserts.h"
#include <stdexcept>
#include <iostream>

using namespace zEngine::common;
using namespace zEngine::devices;

namespace zEngine
{
    Application::Application()
    {
        auto settings = configuration::AppSettings();
        auto appInfo = GetApplicationInfo();

        window = new Window(settings.WindowWidth, settings.WindowHeight, settings.WindowTitle);


        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        VkInstanceCreateInfo info{};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        info.pApplicationInfo = &appInfo;
        info.enabledExtensionCount = glfwExtensionCount;
        info.ppEnabledExtensionNames = glfwExtensions;
        info.enabledLayerCount = 1;
        info.ppEnabledLayerNames = settings.ValidationLayers.data();

        Assert::VulkanSuccess(vkCreateInstance(&info, nullptr, &vkInstance), "Failed to create Vulkan Instance.");

        DeviceBrowser browser;
        browser.FindFirst();
    }

    Application::~Application()
    {
        delete window;
        window = nullptr;

        if (vkInstance != nullptr)
        {
            vkDestroyInstance(vkInstance, nullptr);
            vkInstance = nullptr;
        }
    }

    int Application::Run()
    {
        try
        
        {
            while (!window->shouldClose())
            {
                window->Poll();
            }
        }
        catch (std::exception e)
        {
            std::cerr << "Vulkan-Game terminated abruptly with error:" << std::endl
                << e.what() << std::endl;
                return 1;
        }
        return 0;
    }

    VkApplicationInfo Application::GetApplicationInfo()
    {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.apiVersion = VK_API_VERSION_1_0;
        appInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
        appInfo.pApplicationName = "Vulkan Game";
        appInfo.pEngineName = "zEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(0, 1, 0);

        return appInfo;
    }
}

