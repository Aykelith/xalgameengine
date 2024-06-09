#include <XALGameEngine/Vulkan/Vulkan.hpp>

#include <stdexcept>

namespace XALGE {
	namespace Vulkan {
		std::vector<const char*> defaultValidationLayers = { "VK_LAYER_KHRONOS_validation" };

		VkInstance createInstance(VkInstanceCreateInfo* instanceCreateInfoPtr, VkAllocationCallbacks* allocatorPtr) {
			if (instanceCreateInfoPtr == nullptr) {
				throw std::runtime_error("Called with instanceCreateInfoPtr to nullptr");
			}

			VkInstance instance = VkInstance();

			if (vkCreateInstance(instanceCreateInfoPtr, allocatorPtr, &instance) != VK_SUCCESS) {
				throw std::runtime_error("Failed to create the Vulkan instance");
			}

			return instance;
		}

		VkApplicationInfo createApplicationInfo(std::string_view appName, int appVersioMajor, int appVersionMinor, int appVersionPatch) {
			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = appName.data();
			appInfo.applicationVersion = VK_MAKE_VERSION(appVersioMajor, appVersionMinor, appVersionPatch);
			appInfo.pEngineName = "XALGameEngine";
			appInfo.engineVersion = VK_MAKE_VERSION(0, 0, 1);
			appInfo.apiVersion = VK_API_VERSION_1_0;

			return appInfo;
		}

		VkInstanceCreateInfo createInstanceCreateInfo(VkApplicationInfo* applicationInfo, const std::vector<const char*>& extensions) {
			VkInstanceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.pApplicationInfo = applicationInfo;
			createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
			createInfo.ppEnabledExtensionNames = extensions.data();
			createInfo.enabledLayerCount = 0;

			return createInfo;
		}

		std::vector<VkExtensionProperties> getSupportedExtensions() {
			uint32_t extensionCount = 0;
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

			std::vector<VkExtensionProperties> extensions(extensionCount);
			vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

			return extensions;
		}

		bool checkValidationLayerSupport(const std::vector<const char*>& validationLayers) {
			uint32_t layerCount;
			vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

			std::vector<VkLayerProperties> availableLayers(layerCount);
			vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

			for (const char* layerName : validationLayers) {
				bool layerFound = false;

				for (const auto& layerProperties : availableLayers) {
					if (strcmp(layerName, layerProperties.layerName) == 0) {
						layerFound = true;
						break;
					}
				}

				if (!layerFound) {
					return false;
				}
			}

			return false;
		}

		void addValidationLayersInstanceCreateInfo(VkInstanceCreateInfo* instanceCreateInfoPtr, const std::vector<const char*>& validationLayers) {
			if (!checkValidationLayerSupport()) {
				throw std::runtime_error("Validation layers requested, but not available!");
			}

			instanceCreateInfoPtr->enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			instanceCreateInfoPtr->ppEnabledLayerNames = validationLayers.data();
		}
	}
}