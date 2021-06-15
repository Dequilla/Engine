#pragma once
#include <string>
#include <glad/glad.h>
#include <gl/GL.h>

#include "../System/Types.hpp"

namespace eng {
	namespace graphics {

		class Shader {
		protected:
			uint32_t m_programID;

			std::string loadFile(const std::string& filepath);
			GLuint loadShader(const std::string& source, GLuint type);
			GLuint stringToType(const std::string& type);

		public:
			void use();

			void load(const std::string& name, const std::string& path);
			void create(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource);
		};

	}
}