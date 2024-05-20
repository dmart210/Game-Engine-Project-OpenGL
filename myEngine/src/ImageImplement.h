#pragma once

namespace Engine
{
	class ImageImplement
	{
	public:
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;
		virtual void Bind() const = 0;
		virtual ~ImageImplement() {};
	};

}
