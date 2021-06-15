#include "ForwardRenderer3D.hpp"

namespace eng {
	namespace graphics {

		void ForwardRenderer3D::init()
		{
			m_commands.reserve(1000);
		}

		void ForwardRenderer3D::begin()
		{
			m_commands.clear();
		}

		void ForwardRenderer3D::beginScene()
		{
			// Setup view and projection matrix
		}

		void ForwardRenderer3D::submit(RenderCommand command)
		{
			m_commands.push_back(command);
		}

		void ForwardRenderer3D::endScene()
		{

		}

		void ForwardRenderer3D::end()
		{
		}

		void ForwardRenderer3D::render()
		{
			// Do the shader setups, rendering, lighting etc
			for (const auto& command : m_commands) {


				// Last thing in the loop
				command.renderable->render();
			}
		}

		void ForwardRenderer3D::setViewMatrix(glm::mat4 viewMatrix)
		{
			m_viewMatrix = viewMatrix;
		}

		void ForwardRenderer3D::setProjectionMatrix(glm::mat4 projectionMatrix)
		{
			m_projectionMatrix = projectionMatrix;
		}

	}
}