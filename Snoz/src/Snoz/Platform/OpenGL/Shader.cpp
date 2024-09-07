#include "szPCH.h"
#include "Shader.h"
#include "Snoz/Log.h"

#include <glad/glad.h>

namespace Snoz
{
	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		// Vertex
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* vertexSource = (const GLchar*)vertexSrc.c_str();
		glShaderSource(vertexShaderID, 1, &vertexSource, 0);

		glCompileShader(vertexShaderID);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShaderID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore
			glDeleteShader(vertexShaderID);

			SZ_ERROR("{0}", infoLog.data());
			SZ_ERROR("Vertex shader compilation failed");

			return;
		}
		SZ_INFO("Vertex shader is successfully compiled");

		// Fragment
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* fragmentSource = (const GLchar*)fragmentSrc.c_str();
		glShaderSource(fragmentShaderID, 1, &fragmentSource, 0);

		glCompileShader(fragmentShaderID);

		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShaderID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore
			glDeleteShader(fragmentShaderID);

			SZ_ERROR("{0}", infoLog.data());
			SZ_ERROR("Fragment shader compilation failed");

			return;
		}
		SZ_INFO("Fragment shader is successfully compiled");

		// Program
		m_ShaderProgID = glCreateProgram();

		glAttachShader(m_ShaderProgID, vertexShaderID);
		glAttachShader(m_ShaderProgID, fragmentShaderID);

		glLinkProgram(m_ShaderProgID);

		GLint isLinked = 0;
		glGetProgramiv(m_ShaderProgID, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_ShaderProgID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_ShaderProgID, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore
			glDeleteProgram(m_ShaderProgID);

			// Don't leak shaders either
			glDeleteShader(vertexShaderID);
			glDeleteShader(fragmentShaderID);

			SZ_ERROR("{0}", infoLog.data());
			SZ_ERROR("Shader program link failed");

			return;
		}

		glDetachShader(m_ShaderProgID, vertexShaderID);
		glDetachShader(m_ShaderProgID, fragmentShaderID);

		SZ_INFO("Shader program is successfully linked");
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ShaderProgID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_ShaderProgID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}
}
