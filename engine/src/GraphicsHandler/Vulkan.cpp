#include <XALGameEngine/GraphicsHandler/Vulkan.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>

namespace XALGE {
	namespace GraphicsHandler {
		XALGE::GraphicsAPIEnum Vulkan::getGraphicsAPI() const {
			return XALGE::GraphicsAPIEnum::Vulkan;
		}
	}
}