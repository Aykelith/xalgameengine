#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/LogicManager.hpp>
#include <XALGameEngine/Window/Window.hpp>

namespace XALGE {
	LogicManager::LogicManager()
		: continueLoop{ true }  {
		this->windows.reserve(1);
	}

	void LogicManager::attachWindow(XALGE::Window::Window* const window) {
		this->windows.push_back(window);
		this->shouldContinueLoopFuncs.push_back(window->getCloseWindowCheckerFunc());
		this->loopHandlerFuncs.push_back(window->getHandlerForLogicLoop());
	}

	void LogicManager::startLoop() {
		this->thread = std::thread(&LogicManager::loop, this);
	}

	void LogicManager::triggerStop() {
		this->continueLoop = false;
	}

	void LogicManager::waitToStop() {
		this->thread.join();
	}

	void LogicManager::loop() {
		while (this->shouldContinueLoop()) {
			for (const auto& it : this->loopHandlerFuncs) {
				it();
			}
		}
	}

	bool LogicManager::shouldContinueLoop() {
		if (!continueLoop) return false;

		for (const auto& it : this->shouldContinueLoopFuncs) {
			if (!it()) return false;
		}

		return true;
	}
}