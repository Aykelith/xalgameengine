#include <XALGameEngine/Loop/Loop.hpp>

namespace XALGE {
	namespace Loop {
		void Loop::triggerStop() {
			this->continueLoop = false;
		}

		void Loop::waitToStop() {
			this->thread.join();
		}
	}
}