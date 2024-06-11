#ifndef XALGE_VULKAN_UTILITIES_HPP
#define XALGE_VULKAN_UTILITIES_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
#include <string_view>
#include <vector>
#include <memory>

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		class Vulkan;
	}
}

namespace XALGE {
	namespace Vulkan {
		extern std::vector<const char*> defaultValidationLayers;

		class Utilities {
		public:
			Utilities(XALGE::PlatformSpecificGraphicsHandler::Vulkan* handler);
			// ~Utilities();

			VkInstance createInstance(VkInstanceCreateInfo* instanceCreateInfoPtr, VkAllocationCallbacks* allocatorPtr);
			VkApplicationInfo createApplicationInfo(std::string_view appName, int appVersioMajor, int appVersionMinor, int appVersionPatch);
			VkInstanceCreateInfo createInstanceCreateInfo(VkApplicationInfo* applicationInfo, const std::vector<const char*>& extensions);
			VkInstanceCreateInfo createInstanceCreateInfoWithMinRequiredExtensions(VkApplicationInfo* applicationInfo, const std::vector<const char*>& additionalExtensions = std::vector<const char*>{});
			std::vector<VkExtensionProperties> getSupportedExtensions();
			bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers = defaultValidationLayers);
			void addValidationLayersInstanceCreateInfo(VkInstanceCreateInfo* instanceCreateInfoPtr, const std::vector<const char*>& validationLayers = defaultValidationLayers);

		private:
			XALGE::PlatformSpecificGraphicsHandler::Vulkan* platformSpecificGraphicsHandler;
		};
	}
}

#endif // XALGE_VULKAN_UTILITIES_HPP