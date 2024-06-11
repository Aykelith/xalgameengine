#ifndef XALGE_XALGAMEENGINE_HPP
#define XALGE_XALGAMEENGINE_HPP

#include <memory>
#include <thread>
#include <vector>

#include "LogicManager.hpp"

namespace XALGE {   
    namespace PlatformSpecificGraphicsHandler {
        class Handler;
    }
}

namespace XALGE {
    class XALGameEngine {
    public:
        enum GraphicsAPI {
            Vulkan = 0
        };

        XALGameEngine(XALGE::PlatformSpecificGraphicsHandler::Handler* handler, short intentedNumberOfWindows = 1, short intentedNumberOfLogicManagers = 1);
        ~XALGameEngine();

        void initializeBasicSetup();

        XALGE::Window::Window *const createWindow();

        LogicManager *const createLogicManager();

        template <typename T>
        const T* const getPlatformSpecificGraphicsHandler() const;

        void start();
        void stop();
    private:
        std::unique_ptr<XALGE::PlatformSpecificGraphicsHandler::Handler> platformSpecificGraphicsHandler;

        std::vector<std::unique_ptr<LogicManager>> logicManagers;
        std::vector<std::unique_ptr<XALGE::Window::Window>> windows;
    };

    template <typename T>
    inline const T* const XALGameEngine::getPlatformSpecificGraphicsHandler() const {
        return static_cast<T*>(this->platformSpecificGraphicsHandler.get());
    }
}

#endif // XALGE_XALGAMEENGINE_HPP
