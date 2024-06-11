#ifndef XALGE_LOGIC_MANAGER_HPP
#define XALGE_LOGIC_MANAGER_HPP

#include <thread>
#include <memory>
#include <vector>
#include <functional>

#include "Loop.hpp"

namespace XALGE {
	class XALGameEngine;

	namespace Window {
		class Window;
	}
}

namespace XALGE {
	namespace Loop {
		class LogicLoop: public Loop {
		public:
			LogicLoop();

			void startLoop();

		protected:
			void loop();
			bool shouldContinueLoop();

		private:
			std::vector<std::function<bool()>> shouldContinueLoopFuncs;
			std::vector<std::function<void()>> loopHandlerFuncs;
		};
	}
}

#endif // XALGE_LOGIC_MANAGER_HPP