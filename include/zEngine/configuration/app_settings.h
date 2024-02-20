#pragma once
#include <string>
#include <vector>

namespace zEngine::configuration
{
    class AppSettings
    {
        public:
            const int WindowWidth = 1900;
            const int WindowHeight = 900;
            const std::string WindowTitle = "Hello Vulkan";
            const bool EnableValidationLayers = true;
            const std::vector<const char *> ValidationLayers = {
                "VK_LAYER_KHRONOS_validation"
            };
            const std::vector<const char *> DeviceExtensions = { };
    };
}