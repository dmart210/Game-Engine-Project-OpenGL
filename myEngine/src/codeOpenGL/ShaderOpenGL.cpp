#include "pch.h"
#include "ShaderOpenGL.h"
#include "glad/glad.h"
#include "Utility.h"
#include "stb_image.h"
namespace Engine
{
	ShaderOpenGL::ShaderOpenGL(const std::string& vertexFile, const std::string& fragmentFile)
	{
		std::string vertexShaderSourceCode{ ReadFile(vertexFile) };
		const char* vertexShaderSource{ vertexShaderSourceCode.c_str() };
		std::string fragmentShaderSourceCode{ ReadFile(fragmentFile) };
		const char* fragmentShaderSource{ fragmentShaderSourceCode.c_str() };


		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &(vertexShaderSource), NULL);
		glCompileShader(vertexShader);
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::FRAGMENT::COMP_FAILED\n" << infoLog);
		}

		mShaderProg = glCreateProgram();
		glAttachShader(mShaderProg, vertexShader);
		glAttachShader(mShaderProg, fragmentShader);
		glLinkProgram(mShaderProg);
		//check link error

		glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog);

		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}
	ShaderOpenGL::ShaderOpenGL(std::string&& vertexFile, std::string&& fragmentFile)
	{
		std::string vertexShaderSourceCode{ ReadFile(move(vertexFile)) };
		const char* vertexShaderSource{ vertexShaderSourceCode.c_str() };
		std::string fragmentShaderSourceCode{ ReadFile(move(fragmentFile)) };
		const char* fragmentShaderSource{ fragmentShaderSourceCode.c_str() };


		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &(vertexShaderSource), NULL);
		glCompileShader(vertexShader);
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::FRAGMENT::COMP_FAILED\n" << infoLog);
		}

		mShaderProg = glCreateProgram();
		glAttachShader(mShaderProg, vertexShader);
		glAttachShader(mShaderProg, fragmentShader);
		glLinkProgram(mShaderProg);
		//check link error

		glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
			ENGINE_LOG("ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog);

		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	ShaderOpenGL::~ShaderOpenGL()
	{
		glDeleteProgram(mShaderProg);
	}
	void ShaderOpenGL::Bind()
	{
		glUseProgram(mShaderProg);
	}



	void ShaderOpenGL::SetUniform2Int(const std::string& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProg);
		GLint location{ glGetUniformLocation(mShaderProg, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}
	void ShaderOpenGL::SetUniform2Int(std::string&& uniformName, int val1, int val2)
	{
		glUseProgram(mShaderProg);
		GLint location{ glGetUniformLocation(mShaderProg, uniformName.c_str()) };
		glUniform2i(location, val1, val2);
	}



	std::string ShaderOpenGL::ReadFile(const std::string& fileName)
	{
		std::string result;
		std::ifstream inputFile{ fileName };
		
		std::string line;
		while (inputFile)
		{
			line.clear();
			std::getline(inputFile, line);
			result.append(line);
			result.append("\n");
		}
		return result;
	}
	std::string ShaderOpenGL::ReadFile(std::string&& fileName)
	{
		std::string result;
		std::ifstream inputFile{ move(fileName) };

		std::string line;
		while (inputFile)
		{
			line.clear();
			std::getline(inputFile, line);
			result.append(line);
			result.append("\n");
		}
		return result;
	}
}