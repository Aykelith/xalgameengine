#ifndef XALGE_VULKAN_VULKAN_HPP
#define XALGE_VULKAN_VULKAN_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <string_view>
#include <vector>

namespace XALGE {
	namespace Vulkan {
		extern std::vector<const char*> defaultValidationLayers;

		VkInstance createInstance(VkInstanceCreateInfo* instanceCreateInfoPtr, VkAllocationCallbacks* allocatorPtr);
		VkApplicationInfo createApplicationInfo(std::string_view appName, int appVersioMajor, int appVersionMinor, int appVersionPatch);
		VkInstanceCreateInfo createInstanceCreateInfo(VkApplicationInfo* applicationInfo, const std::vector<const char*>& extensions);
		std::vector<VkExtensionProperties> getSupportedExtensions();
		bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers = defaultValidationLayers);
		void addValidationLayersInstanceCreateInfo(const VkInstanceCreateInfo& instanceCreateInfoPtr, const std::vector<const char*>& validationLayers = defaultValidationLayers);
	}
}

#endif // XALGE_VULKAN_VULKAN_HPP