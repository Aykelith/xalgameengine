#ifndef XALGE_WINDOW_WINDOW_HPP
#define XALGE_WINDOW_WINDOW_HPP

#include <functional>

#include "../Object/Object.hpp"

namespace XALGE {
    namespace Window {
        typedef std::function<bool()> CloseWindowCheckerFunc;
        typedef std::function<void()> LogicLoopHandlerFunc;

        class Window: public XALGE::Object::Object {
        public:
            Window();

            virtual const CloseWindowCheckerFunc getCloseWindowCheckerFunc() const = 0;
            virtual const LogicLoopHandlerFunc getHandlerForLogicLoop() const = 0;
        };
    }
}

#endif XALGE_WINDOW_WINDOW_HPP
