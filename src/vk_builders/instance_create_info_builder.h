#pragma once
#include "vk_builder.h"
#include "engine/engine_vulkan.h"
#include <string>
#include <vector>
#include <set>

namespace vk_builders
{
    class InstanceCreateInfoBuilder : public VkBuilder<VkInstanceCreateInfo>
    {
        private:
            VkInstanceCreateInfo info;

        public:
            InstanceCreateInfoBuilder();

            InstanceCreateInfoBuilder &AddExtensions(const std::vector<const char*> *extensions);
            InstanceCreateInfoBuilder &AddLayers(const std::vector<const char*> *layer);
            InstanceCreateInfoBuilder &AppInfo(const VkApplicationInfo &appInfo);

            virtual const VkInstanceCreateInfo& Build() override;
    };
}