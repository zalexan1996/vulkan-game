#include "device_browser.h"
#include <vulkan/vulkan.h>
#include "application.h"
#include <vector>

namespace zEngine::devices
{
    void DeviceBrowser::FindFirst()
    {
        auto instance = Application::GetSingleton()->GetVkInstance();

        uint32_t count;
        vkEnumeratePhysicalDevices(instance, &count, nullptr);

        std::vector<VkPhysicalDevice*> devices(count);
    
        vkEnumeratePhysicalDevices(instance, &count, *devices.data());
    }
}