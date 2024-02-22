#pragma once
#include "engine/engine_vulkan.h"

namespace vk_builders
{
    class ApplicationInfoBuilder
    {
        public:
            ApplicationInfoBuilder();

            ApplicationInfoBuilder& Api(uint32_t version_major, uint32_t version_minor);
            ApplicationInfoBuilder& Engine(const char * name, uint32_t version_major, uint32_t version_minor);
            ApplicationInfoBuilder& Application(const char * name, uint32_t version_major, uint32_t version_minor);

            const VkApplicationInfo& Build() const {
                return info;
            }

        private:
            VkApplicationInfo info;
    };
}