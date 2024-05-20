#pragma once
#include "Utility.h"
#include "pch.h"
#include "ImageImplement.h"
#include "codeOpenGL/ImageOpenGL.h"
namespace Engine 
{

	class ENGINE_API Image
	{
	public:
		Image(const std::string& filepath);
		Image(const std::string&& filepath);


		int GetWidth() const;
		int GetHeight() const;

		void Bind();


	private:
		std::unique_ptr<ImageImplement> mImplementation;

	};
}