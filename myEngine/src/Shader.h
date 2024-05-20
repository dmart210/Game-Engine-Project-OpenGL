#pragma once
#include "pch.h"
#include "Utility.h"
#include "ShaderImplement.h"



namespace Engine
{
	class ENGINE_API Shader
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		Shader(std::string&& vertexFile, std::string&& fragmentFile);

		void Bind();

		void SetUniform2Int(const std::string& uniformName, int val1, int val2);
		void SetUniform2Int(const std::string&& uniformName, int val1, int val2);

	private:
		std::unique_ptr<ShaderImplement> mImplementation;
	};

}
