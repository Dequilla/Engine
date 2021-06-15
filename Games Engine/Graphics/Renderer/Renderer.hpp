#pragma once

namespace eng {

	namespace graphics {

		class Renderer {
		public:
			virtual void init() = 0;
			virtual void begin() = 0;
			virtual void beginScene() = 0;
			virtual void submit( /* RENDER COMMAND*/) = 0;
			virtual void endScene() = 0;
			virtual void end() = 0;
			virtual void render() = 0;
		};

	}

}