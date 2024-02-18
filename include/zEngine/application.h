#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace zEngine
{
    class Application
    {
        private:
            class Window* window;
            VkInstance vkInstance;
            
            Application();

        public:  
            VkInstance GetVkInstance()
            {
                return GetSingleton()->vkInstance;
            }

            static Application *GetSingleton()
            {
                static Application *instance;
                if (instance == nullptr)
                {
                    instance = new Application();
                }
                
                return instance;
            }

            ~Application();
            Application(const Application&) = delete;
            void operator=(Application const &) = delete;

            int Run();


            VkApplicationInfo GetApplicationInfo();
    };
}