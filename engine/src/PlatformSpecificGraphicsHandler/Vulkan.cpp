#include <XALGameEngine/PlatformSpecificGraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		Vulkan::Vulkan() {}

		XALGE::GraphicsAPIEnum Vulkan::getGraphicsAPI() const {
			return XALGE::GraphicsAPIEnum::Vulkan;
		}
	}
}