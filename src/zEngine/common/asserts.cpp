#include "asserts.h"
#include <stdexcept>

namespace zEngine::common
{
    void Assert::VulkanSuccess(VkResult result, const std::string& message)
    {
        if (result != VK_SUCCESS)
        {
            throw std::runtime_error(std::to_string(result) + " : " + message);
        }
    }
}