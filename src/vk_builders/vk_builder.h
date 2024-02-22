#pragma once

namespace vk_builders
{
    template<class TStruct>
    class VkBuilder
    {
        public:
            virtual const TStruct &Build() = 0;
    };
}