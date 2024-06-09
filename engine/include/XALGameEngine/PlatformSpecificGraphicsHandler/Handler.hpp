#ifndef XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_HANDLER_HPP
#define XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_HANDLER_HPP

// #include <XALGameEngine/GraphicsAPIEnum.hpp>

namespace XALGE {
    class XALGameEngine;
    enum GraphicsAPIEnum;

    namespace Window {
        class Window;
    }
}

namespace XALGE { namespace PlatformSpecificGraphicsHandler {
    class Handler {
    public:
        XALGE::GraphicsAPIEnum getGraphicsAPI() const;

    protected:
        virtual void init() = 0;
        virtual void destroy() = 0;

        friend XALGE::XALGameEngine;

    protected:
        virtual Window::Window* createWindow() = 0;
    };
} }

#endif // XALGE_PLATFORM_SPECIFIC_GRAPHICS_HANDLER_HANDLER_HPP
