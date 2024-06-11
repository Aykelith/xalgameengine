#include <XALGameEngine/PlatformSpecificGraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/Vulkan/Utilities.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		Vulkan::Vulkan()
			: utilities{ XALGE::Vulkan::Utilities(this) } {
		}

		XALGE::GraphicsAPIEnum Vulkan::getGraphicsAPI() const {
			return XALGE::GraphicsAPIEnum::Vulkan;
		}

		const XALGE::Vulkan::Utilities& Vulkan::getUtilities() const {
			return utilities;
		}
	}
}