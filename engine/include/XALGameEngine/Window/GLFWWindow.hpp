#ifndef XALGE_WINDOW_GLFW_WINDOW_HPP
#define XALGE_WINDOW_GLFW_WINDOW_HPP

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
		class GLFWWindow : public Window {
		public:
			~GLFWWindow();

			const CloseWindowCheckerFunc getCloseWindowCheckerFunc() const;
			const LogicLoopHandlerFunc getHandlerForLogicLoop() const;
		protected:
			GLFWWindow(GLFWwindow* window);

			friend XALGE::PlatformSpecificGraphicsHandler::GLFWWithVulkan;
		private:
			GLFWwindow* window;
		};
	}
}

#endif // XALGE_WINDOW_GLFW_WINDOW_HPP