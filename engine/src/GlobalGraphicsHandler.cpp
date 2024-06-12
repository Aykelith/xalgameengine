#include <XALGameEngine/GraphicsHandler/Handler.hpp>
#include <XALGameEngine/GlobalGraphicsHandler.hpp>

namespace XALGE {
	void GlobalGraphicsHandler::set(XALGE::GraphicsHandler::Handler* handler) {
		this->handler = handler;
	}

	GlobalGraphicsHandler GlobalGraphicsHandlerInstance = GlobalGraphicsHandler();
}