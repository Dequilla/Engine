#include "Window.hpp"

#include "Assert.hpp"

namespace eng {
	namespace system {
		Window::Window(std::string title, glm::ivec2 size, glm::ivec2 position, Flags flags)
			: m_size(size), m_position(position), m_flags(flags)
		{
			m_window = SDL_CreateWindow(title.c_str(), m_position.x, m_position.y, m_size.x, m_size.y, flags | Flags::OPENGL | Flags::VISIBLE);
			massert("Window could not be created", m_window != NULL);

			m_context = SDL_GL_CreateContext(m_window);
			massert("GL Context could not be created", m_context != NULL);
		}

		Window::~Window() {
			SDL_GL_DeleteContext(m_context);
			m_context = nullptr;

			SDL_DestroyWindow(m_window);
			m_window = nullptr;
		}

		void Window::setActive()
		{
			SDL_GL_MakeCurrent(m_window, m_context);
		}

		void Window::clear()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void Window::display()
		{
			SDL_GL_SwapWindow(m_window);
		}

		void Window::enableVSYNC(VSYNCMode mode)
		{
			SDL_GL_SetSwapInterval(mode);
		}
	}
}