#include <chrono>

#include "Settings.hpp"

#ifdef USING_GRAPHICS_API_VULKAN
#include <XALGameEngine/PlatformSpecificGraphicsHandler/GLFWWithVulkan.hpp>
#include <XALGameEngine/Vulkan/Vulkan.hpp>
#endif

#include <XALGameEngine/XALGameEngine.hpp>
#include <XALGameEngine/Window/GLFWWindow.hpp>
#include <XALGameEngine/Log.hpp>

int main() {
#ifdef USING_GRAPHICS_API_VULKAN
    INFO("GraphicsAPI: Vulkan");
#endif

#ifdef USING_GRAPHICS_API_VULKAN
    XALGE::XALGameEngine engine = XALGE::XALGameEngine(new XALGE::PlatformSpecificGraphicsHandler::GLFWWithVulkan());

    const auto logicManager = engine.createLogicManager();

    auto vkApplicationInfo = XALGE::Vulkan::createApplicationInfo("Example1", 1, 0, 0);

    //auto platformSpecificGraphicsHandler = engine.getPlatformSpecificGraphicsHandler<GLFWWithVulkan>();
#endif

    const auto window = engine.createWindow();

    VERBOSE_DEBUG("logicManager: " << logicManager);
    VERBOSE_DEBUG("window: " << window);

    logicManager->attachWindow(window);

    // DEBUG(window->tag);

    engine.start();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    engine.stop();

    return 0;
}
