#ifndef XALGE_LOGIC_MANAGER_HPP
#define XALGE_LOGIC_MANAGER_HPP

#include <memory>
#include <vector>
#include <functional>

#include "Loop.hpp"

namespace XALGE {
	namespace Loop {
		class LogicLoop: public Loop {
		public:
			typedef std::function<bool()> ContinueConditionFunc;
			typedef std::function<void()> LoopFunc;

		public:
			LogicLoop();

			void startLoop();

			void addToConditionsToContinue(const ContinueConditionFunc& func);
			void addToLoop(const LoopFunc& func);

		protected:
			void loop();
			bool shouldContinueLoop();

		private:
			std::vector<LogicLoop::ContinueConditionFunc> shouldContinueLoopFuncs;
			std::vector<LogicLoop::LoopFunc> loopHandlerFuncs;
		};
	}
}

#endif // XALGE_LOGIC_MANAGER_HPP