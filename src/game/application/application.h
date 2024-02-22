#pragma once
#include <memory>
#include "engine/instance/instance.h"
#include "engine/window/window.h"
#include "common/config/configuration_loader.h"
#include "engine/devices/logical_device/logical_device.h"
#include "engine/surface/surface.h"

namespace game
{
    class Application
    {
        public:
            Application();
            ~Application();

            void Init();
            void Run();
            bool ShouldClose() const;
            
        protected:
            void Step();

        private:
            std::unique_ptr<engine::Instance> instance_;
            std::unique_ptr<engine::Window> window_;
            std::unique_ptr<engine::devices::LogicalDevice> logical_device_;
            std::unique_ptr<engine::Surface> surface_;

            common::config::Configuration configuration_;
    };
}