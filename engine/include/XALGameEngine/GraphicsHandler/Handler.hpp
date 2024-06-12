#ifndef XALGE_GRAPHICS_HANDLER_HANDLER_HPP
#define XALGE_GRAPHICS_HANDLER_HANDLER_HPP

namespace XALGE {
	class XALGameEngine;
	enum class GraphicsAPIEnum;
}

namespace XALGE {
	namespace GraphicsHandler {
		class Handler {
		public:
			virtual XALGE::GraphicsAPIEnum getGraphicsAPI() const = 0;
		};
	}
}

#endif // XALGE_GRAPHICS_HANDLER_HANDLER_HPP