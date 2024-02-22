#include "instance.h"

#include <iostream>

#include "vk_builders/application_info_builder.h"
#include "vk_builders/instance_create_info_builder.h"
#include "common/asserts.h"

namespace engine
{
    Instance::Instance(const common::config::Configuration &config)
    {
        CreateInstance(config);
    }

    Instance::~Instance()
    {
        if (instance != nullptr)
        {
            vkDestroyInstance(instance, nullptr);
        }
    }

    void Instance::CreateInstance(const common::config::Configuration &config)
    {
        const auto &appInfo = vk_builders::ApplicationInfoBuilder()
            .Application("vulkan-game", 0, 1)
            .Engine("Slasher", 0, 1)
            .Build();

        auto &instanceInfo = vk_builders::InstanceCreateInfoBuilder()
            .AppInfo(appInfo)
            .AddLayers(&config.vulkan_settings_.enabled_layers_)
            .AddExtensions(&config.vulkan_settings_.instance_extensions_)
            .Build();

        common::Assert::VulkanSuccess(vkCreateInstance(&instanceInfo, nullptr, &instance), "Failed to create Vulkan Instance.");
    }
}