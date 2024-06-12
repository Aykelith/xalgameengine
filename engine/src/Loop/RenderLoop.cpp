#include <XALGameEngine/Log.hpp>

#include <XALGameEngine/Loop/RenderLoop.hpp>

namespace XALGE {
	namespace Loop {
		RenderLoop::RenderLoop() {
		}

		void RenderLoop::startLoop() {
			this->thread = std::thread(&RenderLoop::loop, this);
		}

		void RenderLoop::addToConditionsToContinue(const ContinueConditionFunc& func) {
			this->shouldContinueLoopFuncs.push_back(func);
		}

		void RenderLoop::addToLoop(const LoopFunc& func) {
			this->loopHandlerFuncs.push_back(func);
		}

		void RenderLoop::loop() {
			while (this->shouldContinueLoop()) {
				for (const auto& it : this->loopHandlerFuncs) {
					it();
				}
			}
		}

		bool RenderLoop::shouldContinueLoop() {
			if (!continueLoop) return false;

			for (const auto& it : this->shouldContinueLoopFuncs) {
				if (!it()) return false;
			}

			return true;
		}
	}
}