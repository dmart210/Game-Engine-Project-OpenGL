#pragma once

#include "Utility.h"
namespace Engine 
{
	class ENGINE_API EngineApp
	{
	public:
		virtual void Initialize();
		virtual void OnUpdate();
		virtual void ShutDown();
		void Run();

	
	private:
	
	};
}