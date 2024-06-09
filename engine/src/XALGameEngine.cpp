#include <XALGameEngine/XALGameEngine.hpp>
#include <XALGameEngine/Window/Window.hpp>
#include <XALGameEngine/PlatformSpecificGraphicsHandler/Handler.hpp>

namespace XALGE {
    XALGameEngine::XALGameEngine(short intentedNumberOfWindows, short intentedNumberOfLogicManagers) {
        this->windows.reserve(intentedNumberOfWindows);
        this->logicManagers.reserve(intentedNumberOfLogicManagers);
    }

    void XALGameEngine::setGraphicsAPI(PlatformSpecificGraphicsHandler::Handler* handler) {
        this->platformSpecificGraphicsHandler = std::unique_ptr<PlatformSpecificGraphicsHandler::Handler>(handler);

        this->platformSpecificGraphicsHandler->init();
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

        this->platformSpecificGraphicsHandler->destroy();
    }
}
