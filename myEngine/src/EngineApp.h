#pragma once
#include "pch.h"
#include "Utility.h"
#include "HappyEvents.h"

constexpr int FPS{ 60 };
namespace Engine 
{
	class ENGINE_API EngineApp
	{
	public:
		EngineApp();

		virtual void Initialize();
		virtual void OnUpdate();
		virtual void ShutDown();
		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

		void DefaultWindowCloseHandler();

	
	private:
		std::chrono::steady_clock::time_point mNextFrame;
		std::chrono::duration<int, std::chrono::milliseconds::period> mFrameDuration{ 1000 / FPS };
		bool mShouldContinue{ true };

	};
}