#include <XALGameEngine/Log.hpp>

#include <stdexcept>

#include <XALGameEngine/GraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>
#include <XALGameEngine/PlatformSpecificGraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/Vulkan/Instance.hpp>

namespace XALGE {
	namespace GraphicsHandler {
		Vulkan::Vulkan() {}

		XALGE::GraphicsAPIEnum Vulkan::getGraphicsAPI() const {
			return XALGE::GraphicsAPIEnum::Vulkan;
		}

		void Vulkan::init() {
			auto appInfo = XALGE::Vulkan::Instance::createApplicationInfo("Test", 1, 0, 0);

			XAL_DEBUG_START_BLOCK() {
				const auto supportedExtensions = XALGE::Vulkan::Instance::getSupportedExtensions();
				XAL_LOG_INFO("[Vulkan] Supported extensions: (count:" << supportedExtensions.size() << ")");
				for (const auto& extension : supportedExtensions) {
					XAL_LOG_PLAIN("\t" << extension.extensionName);
				}

				const auto supportedLayers = XALGE::Vulkan::Instance::getSupportedLayers();
				XAL_LOG_INFO("[Vulkan] Supported layers: (count:" << supportedLayers.size() << ")");
				for (const auto& layer : supportedLayers) {
					XAL_LOG_PLAIN("\t" << layer.layerName);
				}
			}

			auto extensions = this->vulkanPlatformSpecificGraphicsHandler->getRequiredExtensions();

			XAL_DEBUG_START_BLOCK() {
				extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
			}

			std::vector<const char*> layers = {};

			XAL_DEBUG_START_BLOCK() {
				if (!XALGE::Vulkan::Instance::checkValidationLayersSupport()) {
					throw std::runtime_error("No validation layers support for Vulkan");
				}

				const auto validationLayers = XALGE::Vulkan::Instance::getValidationLayers();
				layers.insert(layers.end(), validationLayers.begin(), validationLayers.end());
			}

			XAL_LOG_INFO("[Vulkan] " << (extensions.size() == 0 ? "No extensions" : "Extensions: (count:" + std::to_string(extensions.size()) + ")"));
			XAL_LOG_PRINT_STRING_VECTOR(extensions);

			XAL_LOG_INFO("[Vulkan] " << (layers.size() == 0 ? "No layers" : "Layers: (count:" + std::to_string(layers.size()) + ")"));
			XAL_LOG_PRINT_STRING_VECTOR(layers);

			auto instanceCreateInfo = XALGE::Vulkan::Instance::createInstanceCreateInfo(&appInfo, extensions, layers);

			XAL_DEBUG_START_BLOCK() {
				XALGE::Vulkan::Debug::addDebugUtilsMessengerCreateInfoToInstanceCreateInfo(&instanceCreateInfo);
			}

			this->instance = XALGE::Vulkan::Instance::createInstance(
				&instanceCreateInfo,
				nullptr
			);

			XALGE::Vulkan::Debug::initializeDebugUtilsMessenger(this->instance, &this->debugMessenger);

			// Choosing physical device
			XAL_DEBUG_START_BLOCK() {
				const auto physicalDevices = XALGE::Vulkan::PhysicalDevice::getAllDevices(this->instance);
				XAL_LOG_INFO("[Vulkan] " << (physicalDevices.size() == 0 ? "No physical devices" : "Physical devices: (count:" + std::to_string(physicalDevices.size()) + ")"));
				for (const auto& device : physicalDevices) {
					const auto deviceProperties = XALGE::Vulkan::PhysicalDevice::getDeviceProperties(device);
					XAL_LOG_PLAIN(
						"\tDevice name: " << deviceProperties.deviceName << " (id:" << deviceProperties.deviceID << ")\n" <<
						"\tDevice type: " << deviceProperties.deviceType << "\n" <<
						"\tAPI version: " << deviceProperties.apiVersion << "\n" <<
						"\t---"
					);
				}
			}

			VkPhysicalDevice physicalDevice = XALGE::Vulkan::PhysicalDevice::pickBestDevice(XALGE::Vulkan::PhysicalDevice::getAllDevices(this->instance));
			XAL_LOG_INFO("[Vulkan] Choosen physical device: " << XALGE::Vulkan::PhysicalDevice::getDeviceProperties(physicalDevice).deviceName);
		}

		void Vulkan::destroy() {
			XAL_DEBUG_START_BLOCK() {
				XALGE::Vulkan::Debug::destroyDebugUtilsMessengerEXT(this->instance, this->debugMessenger, nullptr);
			}

			vkDestroyInstance(this->instance, nullptr);
		}

		void Vulkan::setPlatformSpecificGraphicsHandler(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler) {
			this->vulkanPlatformSpecificGraphicsHandler = static_cast<XALGE::PlatformSpecificGraphicsHandler::Vulkan*>(platformSpecificGraphicsHandler);
		}
	}
}