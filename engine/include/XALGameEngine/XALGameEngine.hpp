#ifndef XALGE_XALGAMEENGINE_HPP
#define XALGE_XALGAMEENGINE_HPP

#include <memory>
#include <thread>
#include <vector>

#include "Loop/LogicLoop.hpp"
#include "Loop/RenderLoop.hpp"

namespace XALGE {
    namespace GraphicsHandler {
        class Handler;
    }

    namespace PlatformSpecificGraphicsHandler {
        class Handler;
    }

    namespace Window {
        class Window;
    }
}

namespace XALGE {
    class XALGameEngine {
    public:
        static XALGameEngine initializeBasicSetup(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler, XALGE::GraphicsHandler::Handler* graphicsHandler);

    public:
        enum GraphicsAPI {
            Vulkan = 0
        };

        XALGameEngine(XALGE::PlatformSpecificGraphicsHandler::Handler* handler, XALGE::GraphicsHandler::Handler* graphicsHandler, short intentedNumberOfWindows = 1, short intentedNumberOfLogicManagers = 1);
        ~XALGameEngine();
        XALGameEngine(XALGameEngine& engine) = default;
        XALGameEngine(XALGameEngine&& engine) = default;

        XALGE::Window::Window *const createWindow();

        XALGE::Loop::LogicLoop *const createLogicLoop();
        XALGE::Loop::RenderLoop* const createRenderLoop();

        template <typename T>
        const T* const getPlatformSpecificGraphicsHandler() const;

        void start();
        void stop();
    private:
        std::unique_ptr<XALGE::PlatformSpecificGraphicsHandler::Handler> platformSpecificGraphicsHandler;

        std::vector<XALGE::Loop::LogicLoop> logicLoops;
        std::vector<XALGE::Loop::RenderLoop> renderLoops;
        std::vector<std::unique_ptr<XALGE::Window::Window>> windows;
    };

    template <typename T>
    inline const T* const XALGameEngine::getPlatformSpecificGraphicsHandler() const {
        return static_cast<T*>(this->platformSpecificGraphicsHandler.get());
    }
}

#endif // XALGE_XALGAMEENGINE_HPP
