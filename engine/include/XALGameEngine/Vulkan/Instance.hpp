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
		namespace Instance {
			VkInstance createInstance(VkInstanceCreateInfo* instanceCreateInfoPtr, VkAllocationCallbacks* allocatorPtr);
			VkApplicationInfo createApplicationInfo(std::string_view appName, int appVersioMajor, int appVersionMinor, int appVersionPatch);
			VkInstanceCreateInfo createInstanceCreateInfo(VkApplicationInfo* applicationInfo, const std::vector<const char*>& extensions, const std::vector<const char*>& layers);
			std::vector<const char*> getValidationLayers();
			std::vector<VkExtensionProperties> getSupportedExtensions();
			std::vector<VkLayerProperties> getSupportedLayers();
			bool checkValidationLayersSupport();
		}

		namespace Debug {
			void initializeDebugUtilsMessenger(VkInstance instance, VkDebugUtilsMessengerEXT* debugMessenger);
			VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
			VkDebugUtilsMessengerCreateInfoEXT createDebugUtilsMessengerCreateInfo();
			void addDebugUtilsMessengerCreateInfoToInstanceCreateInfo(VkInstanceCreateInfo* instanceCreateInfo);
			void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

			VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
		}

		namespace PhysicalDevice {
			std::vector<VkPhysicalDevice> getAllDevices(VkInstance instance);
			VkPhysicalDeviceProperties getDeviceProperties(VkPhysicalDevice device);
			VkPhysicalDeviceFeatures getDeviceFeatures(VkPhysicalDevice device);
			VkPhysicalDevice pickBestDevice(const std::vector<VkPhysicalDevice>& devices);
		}
	}
}

#endif // XALGE_VULKAN_UTILITIES_HPP