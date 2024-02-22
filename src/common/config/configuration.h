#pragma once
#include <vector>
#include "engine/engine_vulkan.h"

namespace common::config
{
    struct Configuration
    {
        struct VulkanSettings
        {
            const char* window_title = "vulkan-game";

            std::vector<const char*> device_extensions_ = { };
            std::vector<const char*> instance_extensions_ = { };

            std::vector<const char*> enabled_layers_ = {
                "VK_LAYER_KHRONOS_validation"
            };
            bool enable_validation_ = true;
        } vulkan_settings_;

        struct UserSettings
        {
            struct DisplaySettings
            {
                int window_width = 1900;
                int window_height = 900;
                bool fullscreen = false;
            } display_settings_;
        } user_settings_;
    };
}