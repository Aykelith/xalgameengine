#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/PlatformSpecificGraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/Vulkan/Instance.hpp>

#include <stdexcept>

namespace XALGE {
	namespace Vulkan {
		namespace Instance {
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

			VkInstanceCreateInfo createInstanceCreateInfo(VkApplicationInfo* applicationInfo, const std::vector<const char*>& extensions, const std::vector<const char*>& layers) {
				VkInstanceCreateInfo createInfo{};
				createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
				createInfo.pApplicationInfo = applicationInfo;
				createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
				createInfo.ppEnabledExtensionNames = extensions.data();
				if (layers.size()) {
					createInfo.enabledLayerCount = static_cast<uint32_t>(layers.size());
					createInfo.ppEnabledLayerNames = layers.data();
				} else {
					createInfo.enabledLayerCount = 0;
				}
				createInfo.enabledLayerCount = 0;

				return createInfo;
			}

			std::vector<const char*> getValidationLayers() {
				return { "VK_LAYER_KHRONOS_validation" };
			}

			std::vector<VkExtensionProperties> getSupportedExtensions() {
				uint32_t extensionCount = 0;
				vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

				std::vector<VkExtensionProperties> extensions(extensionCount);
				vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

				return extensions;
			}

			std::vector<VkLayerProperties> getSupportedLayers() {
				uint32_t layerCount;
				vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

				std::vector<VkLayerProperties> layers(layerCount);
				vkEnumerateInstanceLayerProperties(&layerCount, layers.data());

				return layers;
			}

			bool checkValidationLayersSupport() {
				const auto layers = getSupportedLayers();

				for (const char* layerName : getValidationLayers()) {
					bool layerFound = false;

					for (const auto& layerProperties : layers) {
						if (strcmp(layerName, layerProperties.layerName) == 0) {
							layerFound = true;
							break;
						}
					}

					if (!layerFound) {
						return false;
					}
				}

				return true;
			}
		}

		namespace Debug {
			void initializeDebugUtilsMessenger(VkInstance instance, VkDebugUtilsMessengerEXT* debugMessenger) {
				auto debugUtilsMessengerCreateInfo = createDebugUtilsMessengerCreateInfo();
				if (createDebugUtilsMessengerEXT(instance, &debugUtilsMessengerCreateInfo, nullptr, debugMessenger) != VK_SUCCESS) {
					throw std::runtime_error("failed to set up debug messenger!");
				}
			}

			VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
				auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
				if (func != nullptr) {
					return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
				}
				else {
					return VK_ERROR_EXTENSION_NOT_PRESENT;
				}
			}

			VkDebugUtilsMessengerCreateInfoEXT createDebugUtilsMessengerCreateInfo() {
				VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
				debugCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
				debugCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
				debugCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
				debugCreateInfo.pfnUserCallback = debugCallback;

				return debugCreateInfo;
			}

			void addDebugUtilsMessengerCreateInfoToInstanceCreateInfo(VkInstanceCreateInfo* instanceCreateInfo) {
				auto debugUtilsMessengerCreateInfo = createDebugUtilsMessengerCreateInfo();
				instanceCreateInfo->pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugUtilsMessengerCreateInfo;
			}

			void destroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
				auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
				if (func != nullptr) {
					func(instance, debugMessenger, pAllocator);
				}
			}

			VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData) {
				XAL_LOG_PLAIN_ERROR("[Vulkan] Validation layer: " << pCallbackData->pMessage);

				return VK_FALSE;
			}
		}

		namespace PhysicalDevice {
			std::vector<VkPhysicalDevice> getAllDevices(VkInstance instance) {
				uint32_t devicesCount = 0;
				vkEnumeratePhysicalDevices(instance, &devicesCount, nullptr);

				std::vector<VkPhysicalDevice> devices(devicesCount);
				vkEnumeratePhysicalDevices(instance, &devicesCount, devices.data());

				return devices;
			}

			VkPhysicalDeviceProperties getDeviceProperties(VkPhysicalDevice device) {
				VkPhysicalDeviceProperties deviceProperties;
				vkGetPhysicalDeviceProperties(device, &deviceProperties);
				return deviceProperties;
			}

			VkPhysicalDeviceFeatures getDeviceFeatures(VkPhysicalDevice device) {
				VkPhysicalDeviceFeatures deviceFeatures;
				vkGetPhysicalDeviceFeatures(device, &deviceFeatures);
				return deviceFeatures;
			}

			VkPhysicalDevice pickBestDevice(const std::vector<VkPhysicalDevice>& devices) {
				VkPhysicalDevice currentBestDevice = nullptr;
				int currentBestScore = 0;

				for (const auto& device : devices) {
					int score = 0;

					const auto deviceProperties = getDeviceProperties(device);

					if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
						score += 1000;
					}

					score += deviceProperties.limits.maxImageDimension2D;

					const auto deviceFeatures = getDeviceFeatures(device);
					if (!deviceFeatures.geometryShader) {
						score = 0;
					}

					if (score > currentBestScore) {
						currentBestScore = score;
						currentBestDevice = device;
					}
				}

				return currentBestDevice;
			}
		}

		namespace QueueFamily {

		}
	}
}