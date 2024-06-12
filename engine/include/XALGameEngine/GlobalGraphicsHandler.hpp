#ifndef GLOBAL_GRAPHICS_HANDLER_HPP
#define GLOBAL_GRAPHICS_HANDLER_HPP

namespace XALGE {
	class XALGameEngine;

	namespace GraphicsHandler {
#ifdef USING_GRAPHICS_API_VULKAN
		class Handler;
#endif
	}
}

namespace XALGE {
	class GlobalGraphicsHandler {
	public:
		template <typename T> T* const get();

	protected:
		void set(XALGE::GraphicsHandler::Handler* handler);

		friend XALGameEngine;

	private:
		XALGE::GraphicsHandler::Handler* handler;
	};

	template <typename T>
	inline T* const GlobalGraphicsHandler::get() {
		return static_cast<T*>(this->handler);
	}

	extern XALGE::GlobalGraphicsHandler GlobalGraphicsHandlerInstance;
}

#endif // GLOBAL_GRAPHICS_HANDLER_HPP