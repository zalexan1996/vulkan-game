#include "application.h"
#include "window.h"
#include "app_settings.h"
#include "device_browser.h"
#include "asserts.h"
#include <stdexcept>
#include <iostream>
#include "physical_device.h"
#include "logical_device.h"

using namespace zEngine::common;
using namespace zEngine::devices;

namespace zEngine
{
    Application* Application::instance;

    Application::Application()
    {
        auto settings = configuration::AppSettings();
        auto appInfo = GetApplicationInfo();

        window = std::make_unique<Window>(settings.WindowWidth, settings.WindowHeight, settings.WindowTitle);


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
        window->CreateSurface(vkInstance);
    }

    Application::~Application()
    {
        logicalDevice.reset();
        physicalDevice.reset();
        window.reset();

        if (vkInstance != nullptr)
        {
            vkDestroyInstance(vkInstance, nullptr);
            vkInstance = nullptr;
        }
    }

    Application* Application::GetSingleton()
    {
        if (instance == nullptr)
        {
            instance = new Application();
        }
        
        return instance;
    }

    int Application::Run()
    {
        Init();
        
        while (!window->shouldClose())
        {
            window->Poll();
            Step();
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

    void Application::Init()
    {
        auto browser = DeviceBrowser();
        physicalDevice = std::make_unique<PhysicalDevice>(browser.FindBest());
        logicalDevice = std::make_unique<LogicalDevice>(*physicalDevice);
        auto gfx = logicalDevice->GetQueue(VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT);
        auto tfr = logicalDevice->GetQueue(VkQueueFlagBits::VK_QUEUE_TRANSFER_BIT);
        auto cmp = logicalDevice->GetQueue(VkQueueFlagBits::VK_QUEUE_COMPUTE_BIT);

        std::cout << gfx << " : " << tfr << " : " << cmp << std::endl;
    }

    void Application::Step()
    {

    }
}

