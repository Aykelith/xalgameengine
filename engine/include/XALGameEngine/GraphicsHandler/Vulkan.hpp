#ifndef XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP
#define XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Handler.hpp"

namespace XALGE {
	namespace GraphicsHandler {
		class Vulkan : public Handler {
		public:
			Vulkan();

			XALGE::GraphicsAPIEnum getGraphicsAPI() const;

		private:
			VkInstance instance;
		};
	}
}

#endif // XALGE_VULKAN_GRAPHICS_HANDLER_VULKAN_HPP