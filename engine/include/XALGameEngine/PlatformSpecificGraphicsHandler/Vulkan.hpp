#ifndef XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP
#define XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP

#include <vector>

#include "Handler.hpp"

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		class Vulkan: public Handler {
		public:
			Vulkan();

			XALGE::GraphicsAPIEnum getGraphicsAPI() const;

			virtual std::vector<const char*> getRequiredExtensions() = 0;

		protected:
			virtual void init() = 0;
			virtual void destroy() = 0;
			virtual Window::Window* createWindow() = 0;
		};
	}
}

#endif // XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP