#ifndef XALGE_LOOP_LOOP_HPP
#define XALGE_LOOP_LOOP_HPP

namespace XALGE {
	namespace Loop {
		class Loop {
		public:
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