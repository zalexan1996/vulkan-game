#include "application.h"
#include "common/common.h"
#include <iostream>
#include <chrono>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>
#include "engine/devices/device_browser/device_browser.h"

namespace game
{
    Application::Application()
    {
        engine::Window::InitGlfw();
        
        configuration_ = common::config::ConfigurationLoader().GetConfiguration();

        instance_ = std::make_unique<engine::Instance>(configuration_);
        window_ = std::make_unique<engine::Window>(configuration_);
        surface_ = std::make_unique<engine::Surface>(instance_->Vk(), window_->Glfw());

        auto device = engine::devices::DeviceBrowser(instance_.get()).First();
        logical_device_ = std::make_unique<engine::devices::LogicalDevice>(device.Vk(), configuration_);

        swapchain_ = std::make_unique<engine::graphics::Swapchain>(logical_device_.get(), surface_.get());
    }

    Application::~Application()
    {
        swapchain_.reset();
        logical_device_.reset();
        surface_.reset();
        window_.reset();
        instance_.reset();
    }
    
    void Application::Init()
    {
        logical_device_->GetPhysicalDevice().Print();
    }

    void Application::Run()
    {
        Init();

        while (!ShouldClose())
        {
            Step();
        }
    }

    bool Application::ShouldClose() const
    {
        return window_->ShouldClose();
    }

    void Application::Step()
    {
        window_->Poll();
    }
}