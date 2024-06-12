#ifndef XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_HPP
#define XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_HPP

#include "Handler.hpp"

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		class GLFW: public virtual Handler {
        protected:
            virtual void init() = 0;
            virtual void destroy() = 0;
            virtual Window::Window* createWindow() = 0;

        protected:

		};
	}
}

#endif // XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_HPP