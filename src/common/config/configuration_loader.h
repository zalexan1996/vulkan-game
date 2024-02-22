#pragma once
#include "configuration.h"

namespace common::config
{
    class ConfigurationLoader
    {
        public:
            Configuration GetConfiguration() const;

    };
}