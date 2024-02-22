#include "physical_device.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

namespace engine::devices
{
    
    
    PhysicalDevice::PhysicalDevice(VkPhysicalDevice physical_device)
        : physical_device_(physical_device)
    { }
    
    PhysicalDevice::~PhysicalDevice()
    {

    }

    std::string PhysicalDevice::VersionToString(uint32_t vesion) const
    {
        return std::to_string(VK_API_VERSION_MAJOR(vesion)) 
            + "." + std::to_string(VK_API_VERSION_MINOR(vesion)) 
            + "." + std::to_string(VK_API_VERSION_PATCH(vesion));
    }

    VkPhysicalDeviceProperties PhysicalDevice::GetProperties() const
    {
        VkPhysicalDeviceProperties prop;
        vkGetPhysicalDeviceProperties(physical_device_, &prop);
        return prop;
    }

    VkPhysicalDeviceFeatures PhysicalDevice::GetFeatures() const
    {
        VkPhysicalDeviceFeatures features;
        vkGetPhysicalDeviceFeatures(physical_device_, &features);
        return features;
    }

    QueueInfos PhysicalDevice::GetQueues() const
    {
        uint32_t count;
        vkGetPhysicalDeviceQueueFamilyProperties(Vk(), &count, nullptr);

        std::vector<VkQueueFamilyProperties> props(count);
        vkGetPhysicalDeviceQueueFamilyProperties(Vk(), &count, props.data());

        return QueueInfos(props);
    }

    void PhysicalDevice::Print() const
    {
        uint32_t featuresColumnWidth = 50;
        const auto prop = GetProperties();
        const auto features = GetFeatures();

        std::cout << std::left
            << std::setw(featuresColumnWidth) << "Device Name:" << prop.deviceName << '\n'
            << std::setw(featuresColumnWidth) << "Api Version:" << VersionToString(prop.apiVersion) << '\n'
            << std::setw(featuresColumnWidth) << "Driver Version:" << VersionToString(prop.driverVersion) << '\n'
            << std::setw(featuresColumnWidth) << "Device Type:" << prop.deviceType << '\n'
            << std::setw(featuresColumnWidth) << "Vendor ID:" << prop.vendorID << '\n'
            << std::setw(featuresColumnWidth) << "Device ID:" << prop.deviceID << std::endl << std::endl;

        std::cout << std::left
            << std::setw(featuresColumnWidth) << "Alpha to One:" << std::boolalpha << features.alphaToOne << '\n'
            << std::setw(featuresColumnWidth) << "Depth Bias Clamp:" << std::boolalpha << features.depthBiasClamp << '\n'
            << std::setw(featuresColumnWidth) << "Depth Bounds:" << std::boolalpha << features.depthBounds << '\n'
            << std::setw(featuresColumnWidth) << "Depth Clamp:" << std::boolalpha << features.depthClamp << '\n'
            << std::setw(featuresColumnWidth) << "Draw Indirect First Instance:" << std::boolalpha << features.drawIndirectFirstInstance << '\n'
            << std::setw(featuresColumnWidth) << "Dual Src Blend:" << std::boolalpha << features.dualSrcBlend << '\n'
            << std::setw(featuresColumnWidth) << "Fill Mode Non-Solid:" << std::boolalpha << features.fillModeNonSolid << '\n'
            << std::setw(featuresColumnWidth) << "Fragment Stores and Atomics:" << std::boolalpha << features.fragmentStoresAndAtomics << '\n'
            << std::setw(featuresColumnWidth) << "Full Draw Index uint32:" << std::boolalpha << features.fullDrawIndexUint32 << '\n'
            << std::setw(featuresColumnWidth) << "Geometry Shader:" << std::boolalpha << features.geometryShader << '\n'
            << std::setw(featuresColumnWidth) << "Image Cube Array:" << std::boolalpha << features.imageCubeArray << '\n'
            << std::setw(featuresColumnWidth) << "Independent Blend:" << std::boolalpha << features.independentBlend << '\n'
            << std::setw(featuresColumnWidth) << "Inherited Queries:" << std::boolalpha << features.inheritedQueries << '\n'
            << std::setw(featuresColumnWidth) << "Large Points:" << std::boolalpha << features.largePoints << '\n'
            << std::setw(featuresColumnWidth) << "Logic Op:" << std::boolalpha << features.logicOp << '\n'
            << std::setw(featuresColumnWidth) << "Multi-Draw Indirect:" << std::boolalpha << features.multiDrawIndirect << '\n'
            << std::setw(featuresColumnWidth) << "Multi-Viewport:" << std::boolalpha << features.multiViewport << '\n'
            << std::setw(featuresColumnWidth) << "Occlusion Query Precise:" << std::boolalpha << features.occlusionQueryPrecise << '\n'
            << std::setw(featuresColumnWidth) << "Pipeline Statistics Query:" << std::boolalpha << features.pipelineStatisticsQuery << '\n'
            << std::setw(featuresColumnWidth) << "Robust Buffer Access:" << std::boolalpha << features.robustBufferAccess << '\n'
            << std::setw(featuresColumnWidth) << "Sampler Ansisotropy:" << std::boolalpha << features.samplerAnisotropy << '\n'
            << std::setw(featuresColumnWidth) << "Sample Rate Shading:" << std::boolalpha << features.sampleRateShading << '\n'
            << std::setw(featuresColumnWidth) << "Shader Clip Distance:" << std::boolalpha << features.shaderClipDistance << '\n'
            << std::setw(featuresColumnWidth) << "Shader Cull Distance:" << std::boolalpha << features.shaderCullDistance << '\n'
            << std::setw(featuresColumnWidth) << "Shader float64:" << std::boolalpha << features.shaderFloat64 << '\n'
            << std::setw(featuresColumnWidth) << "Shader Image Gather Extended:" << std::boolalpha << features.shaderImageGatherExtended << '\n'
            << std::setw(featuresColumnWidth) << "Shader int16:" << std::boolalpha << features.shaderInt16 << '\n'
            << std::setw(featuresColumnWidth) << "Shader int64:" << std::boolalpha << features.shaderInt64 << '\n'
            << std::setw(featuresColumnWidth) << "Shader Resource Min Lod:" << std::boolalpha << features.shaderResourceMinLod << '\n'
            << std::setw(featuresColumnWidth) << "Shader Resource Residency:" << std::boolalpha << features.shaderResourceResidency << '\n'
            << std::setw(featuresColumnWidth) << "Shader Sampled Image Array Dynamic Indexing:" << std::boolalpha << features.shaderSampledImageArrayDynamicIndexing << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Buffer Array Dynamic Indexing:" << std::boolalpha << features.shaderStorageBufferArrayDynamicIndexing << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Image Array Dynamic Indexing:" << std::boolalpha << features.shaderStorageImageArrayDynamicIndexing << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Image Extended Formats:" << std::boolalpha << features.shaderStorageImageExtendedFormats << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Image Multisample:" << std::boolalpha << features.shaderStorageImageMultisample << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Image Read Without Format:" << std::boolalpha << features.shaderStorageImageReadWithoutFormat << '\n'
            << std::setw(featuresColumnWidth) << "Shader Storage Image Write Without Format:" << std::boolalpha << features.shaderStorageImageWriteWithoutFormat << '\n'
            << std::setw(featuresColumnWidth) << "Shader Tessellation And Geometry Point Size:" << std::boolalpha << features.shaderTessellationAndGeometryPointSize << '\n'
            << std::setw(featuresColumnWidth) << "Shader Uniform Buffer Array Dynamic Indexing:" << std::boolalpha << features.shaderUniformBufferArrayDynamicIndexing << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Binding:" << std::boolalpha << features.sparseBinding << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency 16 Samples:" << std::boolalpha << features.sparseResidency16Samples << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency 2 Samples:" << std::boolalpha << features.sparseResidency2Samples << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency 4 Samples:" << std::boolalpha << features.sparseResidency4Samples << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency 8 Samples:" << std::boolalpha << features.sparseResidency8Samples << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency Aliased:" << std::boolalpha << features.sparseResidencyAliased << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency Buffer:" << std::boolalpha << features.sparseResidencyBuffer << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency Image 2D:" << std::boolalpha << features.sparseResidencyImage2D << '\n'
            << std::setw(featuresColumnWidth) << "Sparse Residency Image 3D:" << std::boolalpha << features.sparseResidencyImage3D << '\n'
            << std::setw(featuresColumnWidth) << "Tessellation Shader:" << std::boolalpha << features.tessellationShader << '\n'
            << std::setw(featuresColumnWidth) << "Texture Compression ASTC_LDR:" << std::boolalpha << features.textureCompressionASTC_LDR << '\n'
            << std::setw(featuresColumnWidth) << "Texture Compression BC:" << std::boolalpha << features.textureCompressionBC << '\n'
            << std::setw(featuresColumnWidth) << "Texture Compression ETC2:" << std::boolalpha << features.textureCompressionETC2 << '\n'
            << std::setw(featuresColumnWidth) << "Variable Multisample Rate:" << std::boolalpha << features.variableMultisampleRate << '\n'
            << std::setw(featuresColumnWidth) << "Vertex Pipeline Stores and Atomics:" << std::boolalpha << features.vertexPipelineStoresAndAtomics << '\n'
            << std::setw(featuresColumnWidth) << "Wide Lines:" << std::boolalpha << features.wideLines << std::endl << std::endl;
            

        std::cout << "Queues:" << std::endl;
        std::cout << std::setw(12) << "Index" 
        << std::setw(12) << "Count" 
        << std::setw(12) << "Compute" 
        << std::setw(12) << "Graphics" 
        << std::setw(12) << "Transfer" 
        << std::endl;
        const auto queues = GetQueues();
        for (uint32_t i = 0; i < queues.Size(); i++) {
            queues.At(i).Print();
        }

        std::cout << std::endl;
    }
}