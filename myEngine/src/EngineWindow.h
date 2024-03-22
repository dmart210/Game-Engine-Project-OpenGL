#pragma once
#include "WindowImpl.h"
#include "Utility.h"
#include "pch.h"
namespace Engine 
{

	class ENGINE_API EngineWindow
	{

	public:
		static void Init();
		static void Shutdown();
		static EngineWindow* GetWindow();


		void SwapBuffers();
		void PollEvents();
		void Create(int width, int height);
		int GetWidth() const;
		int GetHeight() const; 
 
	private:
		inline static EngineWindow* mInstance{ nullptr };

		std::unique_ptr<WindowImpl> mWindow{nullptr};

		EngineWindow();

	};

}