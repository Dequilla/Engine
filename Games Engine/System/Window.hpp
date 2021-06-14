#pragma once
#include <string>
#include <SDL.h>

#include "../Math/Vector2.hpp"

namespace eng {
	namespace system {
		class Window {
		public:
			enum Flags {
				FULLSCREEN = SDL_WINDOW_FULLSCREEN,
				FULLSCEEN_DESKTOP = SDL_WINDOW_FULLSCREEN_DESKTOP,
				OPENGL = SDL_WINDOW_OPENGL,
				VULKAN = SDL_WINDOW_VULKAN,
				RESIZABLE = SDL_WINDOW_RESIZABLE,
				MINIMIZED = SDL_WINDOW_MINIMIZED,
				MAXIMIZED = SDL_WINDOW_MAXIMIZED,
				VISIBLE = SDL_WINDOW_SHOWN,
				HIDDEN = SDL_WINDOW_HIDDEN
			};

		protected:
			math::Vector2<int> m_size;
			math::Vector2<int> m_position;
			Flags m_flags;

			SDL_Window* m_window;
			SDL_GLContext m_context;

		public:
			Window(std::string title, math::Vector2<int> size, math::Vector2<int> position = {SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED}, Flags flags = Flags::FULLSCREEN);
			~Window();
		};
	}
}