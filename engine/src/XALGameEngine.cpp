#include <XALGameEngine/Global.hpp>

#include <stdexcept>

#include <XALGameEngine/XALGameEngine.hpp>
#include <XALGameEngine/Window/Window.hpp>
#include <XALGameEngine/PlatformSpecificGraphicsHandler/Handler.hpp>
#include <XALGameEngine/GraphicsAPIEnum.hpp>

namespace XALGE {
    XALGameEngine::XALGameEngine(XALGE::PlatformSpecificGraphicsHandler::Handler* handler, short intentedNumberOfWindows, short intentedNumberOfLogicManagers)
        : platformSpecificGraphicsHandler{ std::unique_ptr<PlatformSpecificGraphicsHandler::Handler>(handler) } {
#ifdef USING_GRAPHICS_API_VULKAN
        if (handler->getGraphicsAPI() != XALGE::GraphicsAPIEnum::Vulkan) {
            throw std::runtime_error("Cannot use a non-Vulkan PlatformSpecificGraphicsHandler");
        }
#endif
        this->windows.reserve(intentedNumberOfWindows);
        this->logicManagers.reserve(intentedNumberOfLogicManagers);

        this->platformSpecificGraphicsHandler->init();
    }

    XALGameEngine::~XALGameEngine() {
        this->platformSpecificGraphicsHandler->destroy();
    }

    void XALGameEngine::initializeBasicSetup() {
#ifdef USING_GRAPHICS_API_VULKAN

#endif
    }

    XALGE::Window::Window * const XALGameEngine::createWindow() {
        this->windows.push_back(std::unique_ptr<XALGE::Window::Window>(this->platformSpecificGraphicsHandler->createWindow()));
        return this->windows.back().get();
    }

    LogicManager * const XALGameEngine::createLogicManager() {
        auto logicManager = new LogicManager();
        this->logicManagers.emplace_back(logicManager);
        return this->logicManagers.back().get();
    }

    void XALGameEngine::start() {
        for (const auto& it : this->logicManagers) {
            it->startLoop();
        }
    }
    
    void XALGameEngine::stop() {
        for (const auto& it : this->logicManagers) {
            it->triggerStop();
        }

        for (const auto& it : this->logicManagers) {
            it->waitToStop();
        }
    }
}
