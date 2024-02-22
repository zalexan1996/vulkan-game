#include "common/config/configuration_loader.h"

namespace common::config
{
    Configuration ConfigurationLoader::GetConfiguration() const
    {
        auto output = Configuration();

        uint32_t count;
        const char** extensions = glfwGetRequiredInstanceExtensions(&count);

        // TODO: Replace with STL
        for (size_t i = 0; i < count; i++)
        {
            output.vulkan_settings_.instance_extensions_.push_back(extensions[i]);
        }


        return output;
    }
}