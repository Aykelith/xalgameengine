#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/Window/GLFW.hpp>

#include <GLFW/glfw3.h>

namespace XALGE { namespace Window {
	GLFW::GLFW(GLFWwindow* window)
		: window { window }  {}

	GLFW::~GLFW() {
		glfwDestroyWindow(window);
	}

	const CloseWindowCheckerFunc GLFW::getCloseWindowCheckerFunc() const {
		return [this]()->bool { return !glfwWindowShouldClose(this->window); };
	}

	const LogicLoopHandlerFunc GLFW::getHandlerForLogicLoop() const {
		return [this]()->void {
			glfwPollEvents(); 
		};
	}
} }