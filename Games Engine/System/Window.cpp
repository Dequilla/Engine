#include "Window.hpp"

namespace eng {
	namespace system {
		Window::Window(std::string title, math::Vector2<int> size, math::Vector2<int> position, Flags flags)
			: m_size(size), m_position(position), m_flags(flags)
		{
			m_window = SDL_CreateWindow(title.c_str(), m_position.x, m_position.y, m_size.width, m_size.height, flags | Flags::OPENGL | Flags::VISIBLE);
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
	}
}