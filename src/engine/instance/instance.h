#pragma once
#include "engine/engine_vulkan.h"
#include "common/config/configuration.h"

namespace engine
{
    class Instance
    {
        private:
            VkInstance instance = nullptr;


        protected:
            void CreateInstance(const common::config::Configuration &config);

        public:
            Instance(const common::config::Configuration &config);
            ~Instance();

            VkInstance Vk() const {
                return instance;
            }
    };
}