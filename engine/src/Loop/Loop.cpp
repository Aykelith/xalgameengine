#include <XALGameEngine/Loop/Loop.hpp>

namespace XALGE {
	namespace Loop {
		Loop::Loop()
			: continueLoop{ true } {
		}

		void Loop::triggerStop() {
			this->continueLoop = false;
		}

		void Loop::waitToStop() {
			this->thread.join();
		}
	}
}