#include "application_info_builder.h"

namespace vk_builders
{
    ApplicationInfoBuilder::ApplicationInfoBuilder()
    {
        info = {};
        info.sType = VkStructureType::VK_STRUCTURE_TYPE_APPLICATION_INFO;
        info.apiVersion = VK_API_VERSION_1_3;
    }

    ApplicationInfoBuilder& ApplicationInfoBuilder::Api(uint32_t version_major, uint32_t version_minor)
    {
        info.apiVersion = VK_MAKE_API_VERSION(0, version_major, version_minor, 0);
        return *this;
    }

    ApplicationInfoBuilder &ApplicationInfoBuilder::Engine(const char * name, uint32_t version_major, uint32_t version_minor)
    {
        info.pEngineName = name;
        info.engineVersion = VK_MAKE_API_VERSION(0, version_major, version_minor, 0);

        return *this;
    }

    ApplicationInfoBuilder &ApplicationInfoBuilder::Application(const char * name, uint32_t version_major, uint32_t version_minor)
    {
        info.pApplicationName = name;
        info.applicationVersion = VK_MAKE_API_VERSION(0, version_major, version_minor, 0);

        return *this;
    }
}