#include "pch.h"
#include "EngineApp.h"
#include "EngineWindow.h"

namespace Engine
{
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
		EngineWindow::Init();
		EngineWindow::GetWindow()->Create(1000, 800);
		Initialize();
		while (true) {
			OnUpdate();

			EngineWindow::GetWindow()->SwapBuffers();
			EngineWindow::GetWindow()->PollEvents();

		}
		ShutDown();
		EngineWindow::Shutdown();

	}
}