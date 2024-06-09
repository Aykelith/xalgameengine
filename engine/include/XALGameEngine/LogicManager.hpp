#ifndef XALGE_LOGIC_MANAGER_HPP
#define XALGE_LOGIC_MANAGER_HPP

#include <thread>
#include <memory>
#include <vector>
#include <functional>

namespace XALGE {
	class XALGameEngine;

	namespace Window {
		class Window;
	}
}

namespace XALGE {
	class LogicManager {
	public:
		void attachWindow(XALGE::Window::Window * const window);

	protected:
		LogicManager();

		void startLoop();
		void triggerStop();
		void waitToStop();

		friend XALGameEngine;

	private:
		void loop();

		bool shouldContinueLoop();

	private:
		std::thread thread;

		std::vector<XALGE::Window::Window *> windows;

		std::vector<std::function<bool()>> shouldContinueLoopFuncs;
		std::vector<std::function<void()>> loopHandlerFuncs;

		bool continueLoop;
	};
}

#endif // XALGE_LOGIC_MANAGER_HPP