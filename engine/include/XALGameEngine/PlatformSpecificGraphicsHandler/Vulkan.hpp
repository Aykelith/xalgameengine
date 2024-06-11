#ifndef XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP
#define XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP

#include <vector>

#include "Handler.hpp"

namespace XALGE {
	namespace Vulkan {
		class Utilities;
	}
}

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		class Vulkan: virtual public Handler {
		public:
			Vulkan();

			XALGE::GraphicsAPIEnum getGraphicsAPI() const;

			const XALGE::Vulkan::Utilities& getUtilities() const;

			virtual std::vector<const char*> getRequiredExtensions() = 0;
		protected:
			const XALGE::Vulkan::Utilities& utilities;
		};
	}
}

#endif // XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_VULKAN_HPP