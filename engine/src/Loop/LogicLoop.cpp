#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/Loop/LogicLoop.hpp>

namespace XALGE {
	namespace Loop {
		LogicLoop::LogicLoop() {
		}

		void LogicLoop::startLoop() {
			this->thread = std::thread(&LogicLoop::loop, this);
		}

		void LogicLoop::addToConditionsToContinue(const ContinueConditionFunc& func) {
			this->shouldContinueLoopFuncs.push_back(func);
		}

		void LogicLoop::addToLoop(const LoopFunc& func) {
			this->loopHandlerFuncs.push_back(func);
		}

		void LogicLoop::loop() {
			while (this->shouldContinueLoop()) {
				for (const auto& it : this->loopHandlerFuncs) {
					it();
				}
			}
		}

		bool LogicLoop::shouldContinueLoop() {
			if (!continueLoop) return false;

			for (const auto& it : this->shouldContinueLoopFuncs) {
				if (!it()) return false;
			}

			return true;
		}
	}
}