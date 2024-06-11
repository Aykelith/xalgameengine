#ifndef XALGE_WINDOW_GLFW_HPP
#define XALGE_WINDOW_GLFW_HPP

#include "Window.hpp"

#include <memory>

struct GLFWwindow;

namespace XALGE {
	namespace PlatformSpecificGraphicsHandler {
		class GLFWWithVulkan;
	}
}

namespace XALGE {
	namespace Window {
		class GLFW : public Window {
		public:
			~GLFW();

			const CloseWindowCheckerFunc getCloseWindowCheckerFunc() const;
			const LogicLoopHandlerFunc getHandlerForLogicLoop() const;
		protected:
			GLFW(GLFWwindow* window);

			friend XALGE::PlatformSpecificGraphicsHandler::GLFWWithVulkan;
		private:
			GLFWwindow* window;
		};
	}
}

#endif // XALGE_WINDOW_GLFW_HPP