#pragma once
#include <glm.hpp>

#include "Renderer.hpp"

namespace eng {
	namespace graphics {

		class ForwardRenderer3D : public Renderer {
		protected:
			glm::mat4 m_projectionMatrix;
			glm::mat4 m_viewMatrix;

		public:
			void init() override;
			void begin() override;
			void beginScene() override;
			void submit(RenderCommand command) override;
			void endScene() override;
			void end() override;
			void render() override;

			void setViewMatrix(glm::mat4 viewMatrix);
			void setProjectionMatrix(glm::mat4 projectionMatrix);
		};

	}
}