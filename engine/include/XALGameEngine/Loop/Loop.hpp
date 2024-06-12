#ifndef XALGE_LOOP_LOOP_HPP
#define XALGE_LOOP_LOOP_HPP

#include <thread>

namespace XALGE {
	namespace Loop {
		class Loop {
		public:
			Loop();

			virtual void startLoop() = 0;
			virtual void triggerStop();
			virtual void waitToStop();

		protected:
			virtual void loop() = 0;
			virtual bool shouldContinueLoop() = 0;

		protected:
			std::thread thread;

			bool continueLoop;
		};
	}
}

#endif // XALGE_LOOP_LOOP_HPP