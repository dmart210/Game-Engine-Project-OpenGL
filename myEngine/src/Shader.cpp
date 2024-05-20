#include "pch.h"
#include  "Shader.h"
#include "codeOpenGL/ShaderOpenGL.h"

namespace Engine
{
	Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef ENGINE_OPENGL
		mImplementation = std::unique_ptr<ShaderImplement>{ new ShaderOpenGL{vertexFile, fragmentFile} };
#else
		#only_openGL_is_supported_so_far
#endif

	}
	Shader::Shader(std::string&& vertexFile, std::string&& fragmentFile)
	{
#ifdef ENGINE_OPENGL
		mImplementation = std::unique_ptr<ShaderImplement>{ new ShaderOpenGL{move(vertexFile), move(fragmentFile)} };
#else
		#only_openGL_is_supported_so_far
#endif
	}
	void Shader::Bind()
	{
		mImplementation->Bind();
	}
	void Shader::SetUniform2Int(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Int(uniformName, val1, val2);
	}
	void Shader::SetUniform2Int(const std::string&& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Int(move(uniformName), val1, val2);

	}
}