#pragma once
#include "engine/engine_vulkan.h"
#include "common/config/configuration.h"
#include "engine/instance/instance.h"

namespace engine
{
    class Window
    {
        private:
            GLFWwindow* window = nullptr;

        protected:
            GLFWwindow *CreateWindow(const common::config::Configuration &config);

        public:
            Window(const common::config::Configuration &config);
            ~Window();
            
            static void InitGlfw();
            void Poll();
            bool ShouldClose() const;
            GLFWwindow* Glfw() {
                return window;
            }
    };
}