#ifndef XALGE_RENDER_MANAGER_HPP
#define XALGE_RENDER_MANAGER_HPP

#include <memory>
#include <vector>
#include <functional>

#include "Loop.hpp"

namespace XALGE {
	namespace Loop {
		class RenderLoop : public Loop {
		public:
			typedef std::function<bool()> ContinueConditionFunc;
			typedef std::function<void()> LoopFunc;

		public:
			RenderLoop();

			void startLoop();

			void addToConditionsToContinue(const ContinueConditionFunc& func);
			void addToLoop(const LoopFunc& func);

		protected:
			void loop();
			bool shouldContinueLoop();

		private:
			std::vector<RenderLoop::ContinueConditionFunc> shouldContinueLoopFuncs;
			std::vector<RenderLoop::LoopFunc> loopHandlerFuncs;
		};
	}
}

#endif // XALGE_RENDER_MANAGER_HPP