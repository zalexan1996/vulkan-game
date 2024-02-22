#include "instance_create_info_builder.h"

namespace vk_builders
{
    InstanceCreateInfoBuilder::InstanceCreateInfoBuilder()
    {
        info = {};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    }
    
    InstanceCreateInfoBuilder &InstanceCreateInfoBuilder::AddExtensions(const std::vector<const char*>* extensions)
    {
        info.enabledExtensionCount = extensions->size();
        info.ppEnabledExtensionNames = extensions->data();

        return *this;
    }
    
    InstanceCreateInfoBuilder &InstanceCreateInfoBuilder::AddLayers(const std::vector<const char*>* layers)
    {
        info.enabledLayerCount = layers->size();
        info.ppEnabledLayerNames = layers->data();

        return *this;
    }
    
    InstanceCreateInfoBuilder &InstanceCreateInfoBuilder::AppInfo(const VkApplicationInfo &appInfo)
    {
        info.pApplicationInfo = &appInfo;
        return *this;
    }

    const VkInstanceCreateInfo& InstanceCreateInfoBuilder::Build()
    {
        return info;
    }
}