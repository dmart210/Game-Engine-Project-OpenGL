#pragma once
#include "Utility.h"

namespace Engine
{
	class ENGINE_API KeyPressed
	{
	public: 
		KeyPressed(int kCode);

		int GetKeyCode() const;


	private:
		int mKeyCode;
	};

	class ENGINE_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;

	};
}