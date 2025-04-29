#ifndef XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP
#define XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Handler.hpp"

namespace XALGE {
	enum class GraphicsAPIEnum;

	namespace PlatformSpecificGraphicsHandler {
		class Vulkan;
	}
}

namespace XALGE {
	namespace GraphicsHandler {
		class Vulkan : public Handler {
		public:
			Vulkan();

			XALGE::GraphicsAPIEnum getGraphicsAPI() const;

			virtual void init();
			virtual void destroy();

			void setPlatformSpecificGraphicsHandler(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler);

		private:
			XALGE::PlatformSpecificGraphicsHandler::Vulkan* vulkanPlatformSpecificGraphicsHandler;

			VkInstance instance;
			VkDebugUtilsMessengerEXT debugMessenger;
		};
	}
}

#endif // XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP