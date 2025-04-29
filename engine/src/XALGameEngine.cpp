#include <XALGameEngine/Global.hpp>

#include <stdexcept>

#include <XALGameEngine/XALGameEngine.hpp>
#include <XALGameEngine/Window/Window.hpp>
#include <XALGameEngine/PlatformSpecificGraphicsHandler/Handler.hpp>
#include <XALGameEngine/GraphicsHandler/Handler.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>
#include <XALGameEngine/GlobalGraphicsHandler.hpp>

namespace XALGE {
    XALGameEngine XALGameEngine::initializeBasicSetup(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler, XALGE::GraphicsHandler::Handler* graphicsHandler) {
        XALGameEngine engine = XALGameEngine(platformSpecificGraphicsHandler, graphicsHandler, 1, 1);

        auto logicLoop = engine.createLogicLoop();
        auto renderLoop = engine.createRenderLoop();

        auto window = engine.createWindow();

        logicLoop->addToConditionsToContinue(window->getCloseWindowCheckerFunc());
        logicLoop->addToLoop(window->getHandlerForLogicLoop());

        renderLoop->addToConditionsToContinue(window->getCloseWindowCheckerFunc());
        renderLoop->addToLoop(window->getHandlerForLogicLoop());

#ifdef USING_GRAPHICS_API_VULKAN

#endif

        return engine;
    }

    XALGameEngine::XALGameEngine(XALGE::PlatformSpecificGraphicsHandler::Handler* platformSpecificGraphicsHandler, XALGE::GraphicsHandler::Handler* graphicsHandler, short intentedNumberOfWindows, short intentedNumberOfLogicManagers)
        : platformSpecificGraphicsHandler{ std::unique_ptr<PlatformSpecificGraphicsHandler::Handler>(platformSpecificGraphicsHandler) }
        , graphicsHandler{ std::unique_ptr<GraphicsHandler::Handler>(graphicsHandler) } {
#ifdef USING_GRAPHICS_API_VULKAN
        if (platformSpecificGraphicsHandler->getGraphicsAPI() != XALGE::GraphicsAPIEnum::Vulkan) {
            throw std::runtime_error("Cannot use a non-Vulkan PlatformSpecificGraphicsHandler");
        }
#endif

        if (graphicsHandler->getGraphicsAPI() != platformSpecificGraphicsHandler->getGraphicsAPI()) {
            throw std::runtime_error("The PlatformSpecificGraphicsHandler graphics API is different from the one of GraphicsHandler");
        }

        graphicsHandler->setPlatformSpecificGraphicsHandler(platformSpecificGraphicsHandler);

        this->windows.reserve(intentedNumberOfWindows);
        this->logicLoops.reserve(intentedNumberOfLogicManagers);

        this->platformSpecificGraphicsHandler->init();
        this->graphicsHandler->init();

        GlobalGraphicsHandlerInstance.set(graphicsHandler);
    }

    XALGameEngine::~XALGameEngine() {
        if (this->platformSpecificGraphicsHandler) this->platformSpecificGraphicsHandler->destroy();
        if (this->graphicsHandler) this->graphicsHandler->destroy();
    }
    
    // XALGameEngine::XALGameEngine(XALGameEngine& engine) {}

    // XALGameEngine::XALGameEngine(XALGameEngine&& engine) {}

    XALGE::Window::Window * const XALGameEngine::createWindow() {
        this->windows.push_back(std::unique_ptr<XALGE::Window::Window>(this->platformSpecificGraphicsHandler->createWindow()));
        return this->windows.back().get();
    }

    XALGE::Loop::LogicLoop* const XALGameEngine::createLogicLoop() {
        this->logicLoops.emplace_back();
        return &this->logicLoops.back();
    }

    XALGE::Loop::RenderLoop* const XALGameEngine::createRenderLoop() {
        this->renderLoops.emplace_back();
        return &this->renderLoops.back();
    }

    void XALGameEngine::start() {
        for (auto& it : this->logicLoops) {
            it.startLoop();
        }

        for (auto& it : this->renderLoops) {
            it.startLoop();
        }
    }
    
    void XALGameEngine::stop() {
        for (auto& it : this->logicLoops) {
            it.triggerStop();
        }

        for (auto& it : this->renderLoops) {
            it.triggerStop();
        }

        for (auto& it : this->logicLoops) {
            it.waitToStop();
        }

        for (auto& it : this->renderLoops) {
            it.waitToStop();
        }
    }
}
