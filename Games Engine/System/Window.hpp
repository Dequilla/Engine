#pragma once
#include <glad/glad.h>

#include <string>
#include <SDL.h>
#include <SDL_opengl.h>
#include <glm.hpp>

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
			glm::ivec2 m_size;
			glm::ivec2 m_position;
			Flags m_flags;

			SDL_Window* m_window;
			SDL_GLContext m_context;

		public:
			Window(std::string title, glm::ivec2 size, glm::ivec2 position = { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, Flags flags = Flags::VISIBLE);
			~Window();

			void setActive();

			void clear();
			void display();

			enum VSYNCMode {
				OFF = 0,
				SYNCHRONIZED = 1,
				ADAPTIVE = -1
			};
			void enableVSYNC(VSYNCMode mode = VSYNCMode::SYNCHRONIZED);
		};
	}
}