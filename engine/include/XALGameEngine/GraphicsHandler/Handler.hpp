#ifndef XALGE_GRAPHICS_HANDLER_HANDLER_HPP
#define XALGE_GRAPHICS_HANDLER_HANDLER_HPP

namespace XALGE {
	enum class GraphicsAPIEnum;

	namespace PlatformSpecificGraphicsHandler {
		class Handler;
	}
}

namespace XALGE {
	namespace GraphicsHandler {
		class Handler {
		public:
			virtual XALGE::GraphicsAPIEnum getGraphicsAPI() const = 0;

			virtual void init() = 0;
			virtual void destroy() = 0;
			virtual void setPlatformSpecificGraphicsHandler(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler) = 0;
		};
	}
}

#endif // XALGE_GRAPHICS_HANDLER_HANDLER_HPP