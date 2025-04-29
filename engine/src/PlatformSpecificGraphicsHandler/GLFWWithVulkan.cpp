#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <XALGameEngine/PlatformSpecificGraphicsHandler/GLFWWithVulkan.hpp>
#include <XALGameEngine/Window/GLFW.hpp>

#include <stdexcept>

namespace XALGE { 
    namespace PlatformSpecificGraphicsHandler {
        GLFWWithVulkan::GLFWWithVulkan() {

        }

        XALGE::GraphicsAPIEnum GLFWWithVulkan::getGraphicsAPI() const {
            return Vulkan::getGraphicsAPI();
        }

        std::vector<const char*> GLFWWithVulkan::getRequiredExtensions() {
            uint32_t extensionsCount;
            const auto extensions = glfwGetRequiredInstanceExtensions(&extensionsCount);
            return std::vector<const char*>(extensions, extensions + extensionsCount);
        }

        void GLFWWithVulkan::init() {
            if (!glfwInit()) {
                throw std::runtime_error("Initialiation of GLFW failed");
            }
        
            if (!glfwVulkanSupported()) {
                throw std::runtime_error("Initialiation of Vulkan failed");
            }

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        }

        void GLFWWithVulkan::destroy() {
            glfwTerminate();
        }

        XALGE::Window::Window* GLFWWithVulkan::createWindow() {
            return new XALGE::Window::GLFW(glfwCreateWindow(640, 480, "Window Title", nullptr, nullptr));
        }
    }
}
