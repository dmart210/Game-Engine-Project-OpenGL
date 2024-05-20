#pragma once

namespace Engine
{
	class ShaderImplement
	{
	public:
		virtual void Bind() = 0;

		virtual void SetUniform2Int(const std::string& uniformName, int val1, int val2) = 0;
		virtual void SetUniform2Int(std::string&& uniformName, int val1, int val2) = 0;

		virtual ~ShaderImplement() {};
	};
}