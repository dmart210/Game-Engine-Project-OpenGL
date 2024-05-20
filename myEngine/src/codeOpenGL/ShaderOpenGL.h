#pragma once
#include "pch.h"
#include "../ShaderImplement.h"

namespace Engine
{
	class ShaderOpenGL : public ShaderImplement
	{
	public:
		ShaderOpenGL(const std::string& vertexFile, const std::string& fragmentFile);
		ShaderOpenGL( std::string&& vertexFile, std::string&& fragmentFile);
		~ShaderOpenGL();

		virtual void Bind() override;

		virtual void SetUniform2Int(const std::string& uniformName, int val1, int val2) override;
		virtual void SetUniform2Int(std::string&& uniformName, int val1, int val2) override;


	private:
		unsigned int mShaderProg{ 0 };
		std::string ReadFile(const std::string& fileName);
		std::string ReadFile(std::string&& fileName);
	};
}