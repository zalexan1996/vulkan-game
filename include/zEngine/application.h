#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <memory>


namespace zEngine
{
    namespace devices{
        class LogicalDevice;
        class PhysicalDevice;
    }
    class Application
    {
        private:
            std::unique_ptr<class Window> window;
            std::unique_ptr<devices::LogicalDevice> logicalDevice;
            std::unique_ptr<devices::PhysicalDevice> physicalDevice;
            VkInstance vkInstance;
            static Application* instance;
            
            Application();

        public:  
            static Application* GetSingleton();
            static VkInstance GetVkInstance()
            {
                return GetSingleton()->vkInstance;
            }


            ~Application();
            Application(const Application&) = delete;
            void operator=(Application const &) = delete;

            int Run();


            VkApplicationInfo GetApplicationInfo();

        protected:
            virtual void Init();
            virtual void Step();
    };
}