#include "pch.h"
#include "EngineApp.h"
#include "EngineWindow.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"
#include "Image.h"
#include "Shader.h"
#include "Renderer.h"
#include "HappyKeys.h"

namespace Engine
{
	EngineApp::EngineApp()
	{
		EngineWindow::Init();
		EngineWindow::GetWindow()->Create(1000, 800);

		Renderer::Init();
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler();  });

	}
	void EngineApp::Initialize()
	{
	}
	void EngineApp::OnUpdate()
	{
	}
	void EngineApp::ShutDown()
	{
	}
	void EngineApp::Run()
	{

		Initialize();
		mNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

		while (mShouldContinue) {
			Renderer::ClearScreen();
			
			OnUpdate();

			std::this_thread::sleep_until(mNextFrame);
			mNextFrame = std::chrono::steady_clock::now() + mFrameDuration;

			EngineWindow::GetWindow()->SwapBuffers();
			EngineWindow::GetWindow()->PollEvents();

		}
		ShutDown();
		EngineWindow::Shutdown();

	}

	void EngineApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		EngineWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void EngineApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		EngineWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void EngineApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		EngineWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void EngineApp::DefaultWindowCloseHandler()
	{
		mShouldContinue = false;
	}








}