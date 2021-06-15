#pragma once
#include "RenderCommand.hpp"

namespace eng {

	namespace graphics {

		class Renderer {
		protected:
			CommandQueue m_commands;

		public:
			virtual void init() = 0;
			virtual void begin() = 0;
			virtual void beginScene() = 0;
			virtual void submit(RenderCommand command) = 0;
			virtual void endScene() = 0;
			virtual void end() = 0;
			virtual void render() = 0;
		};

	}

}