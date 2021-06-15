#include "Shader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


#include "../System/Assert.hpp"

namespace eng {
	namespace graphics {

		std::string Shader::loadFile(const std::string& filepath)
		{
			std::string contents;
			std::ifstream file;
			file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

			try
			{
				file.open(filepath);
				std::stringstream stream;
				stream << file.rdbuf();
				file.close();

				contents = stream.str();
			}
			catch (std::ifstream::failure e)
			{
				std::cout << "Could not read shader file " << filepath << std::endl;
				massert("Failed to load shader file.", false);
			}

			return contents;
		}

		GLuint Shader::loadShader(const std::string& source, GLuint type)
		{
			GLuint shaderID;
			int success;
			char infoLog[512];

			const GLchar* cSource = source.c_str();

			// Create, compile, link shaders
			shaderID = glCreateShader(type);
			glShaderSource(shaderID, 1, &cSource, NULL);
			glCompileShader(shaderID);

			// Check for errors
			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
				std::cout << "Failed compiling shader\n Info Log: " << std::string(infoLog) << std::endl;
			}

			return shaderID;
		}

		GLuint Shader::stringToType(const std::string& type)
		{
			if (type == "vertex") return GL_VERTEX_SHADER;
			else if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;
			
			massert("Invlid shader type provided has to be (vertex, fragment or pixel)", false);
		}

		void Shader::use()
		{
			glUseProgram(m_programID);
		}

		void Shader::load(const std::string& name, const std::string& path)
		{
			std::string vertexPath, fragmentPath;
			vertexPath = path + "/" + name + ".vs";
			fragmentPath = path + "/" + name + ".fs";

			std::string vSource = loadFile(vertexPath);
			std::string fSource = loadFile(fragmentPath);

			create(name, vSource, fSource);
		}

		void Shader::create(const std::string& name, const std::string& vertexSource, const std::string& fragmentSource)
		{
			GLuint vShader = loadShader(vertexSource, stringToType("vertex"));
			GLuint fShader = loadShader(fragmentSource, stringToType("fragment"));

			// Create and link to program
			m_programID = glCreateProgram();
			glAttachShader(m_programID, vShader);
			glAttachShader(m_programID, fShader);
			glLinkProgram(m_programID);

			// Check for errors
			int success;
			char infoLog[512];

			glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(m_programID, 512, NULL, infoLog);
				std::cout << "Failed linking shader program\n Info Log : " << std::string(infoLog) << std::endl;
				massert("Failed linking shader program", false);
			}

			glDeleteShader(vShader);
			glDeleteShader(fShader);
		}

	}
}