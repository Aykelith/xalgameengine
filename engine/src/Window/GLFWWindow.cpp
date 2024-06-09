#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/Window/GLFWWindow.hpp>

#include <GLFW/glfw3.h>

namespace XALGE { namespace Window {
	GLFWWindow::GLFWWindow(GLFWwindow* window)
		: window { window }  {}

	GLFWWindow::~GLFWWindow() {
		glfwDestroyWindow(window);
	}

	const CloseWindowCheckerFunc GLFWWindow::getCloseWindowCheckerFunc() const {
		return [this]()->bool { return !glfwWindowShouldClose(this->window); };
	}

	const LogicLoopHandlerFunc GLFWWindow::getHandlerForLogicLoop() const {
		return [this]()->void {
			glfwPollEvents(); 
		};
	}
} }