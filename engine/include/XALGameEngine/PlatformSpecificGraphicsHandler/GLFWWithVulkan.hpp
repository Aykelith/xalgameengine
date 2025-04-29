#ifndef XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_WITH_VULKAN_HPP
#define XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_WITH_VULKAN_HPP

#include "Vulkan.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace XALGE { 
    namespace PlatformSpecificGraphicsHandler {
        class GLFWWithVulkan: public Vulkan {
        public:
            GLFWWithVulkan();

            XALGE::GraphicsAPIEnum getGraphicsAPI() const;

            std::vector<const char*> getRequiredExtensions();
        protected:
            void init();
            void destroy();
            XALGE::Window::Window* createWindow();
        };
    } 
}

#endif // XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_GLFW_WITH_VULKAN_HPP

