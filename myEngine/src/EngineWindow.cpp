#include "pch.h"
#include "EngineWindow.h"
#include "codeGLFW/WindowGLFW.h"
#include "HappyEvents.h"

namespace Engine {
	EngineWindow::EngineWindow()
	{
#ifdef ENGINE_GLFW_WINDOW
		mWindow = std::unique_ptr<WindowImpl>{new WindowGLFW};
#else
		#definition_ENGINE_GLFW_is_missing
#endif
	}

	void EngineWindow::Init()
	{
		if (!mInstance)
			mInstance = new EngineWindow;
	}

	void EngineWindow::Shutdown()
	{
		if (mInstance) delete mInstance;
	}

	EngineWindow* EngineWindow::GetWindow()
	{
		return mInstance;
	}

	void EngineWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void EngineWindow::PollEvents()
	{
		mWindow->PollEvents();

	}

	void EngineWindow::Create(int width, int height)
	{
		mWindow->Create(width, height);
	}

	int EngineWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int EngineWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}


	void EngineWindow::SetKeyPressedCallback(std::function<void(const KeyPressed&)>& callbackFunc)
	{
		mWindow->SetKeyPressedCallback(callbackFunc);
	}
	void EngineWindow::SetKeyReleasedCallback(std::function<void(const KeyReleased&)>& callbackFunc)
	{
		mWindow->SetKeyReleasedCallback(callbackFunc);
	}
	void EngineWindow::SetWindowCloseCallback(std::function<void()>& callbackFunc)
	{
		mWindow->SetWindowCloseCallback(callbackFunc);
	}
}