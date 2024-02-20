#include "pch.h"
#include "EngineApp.h"


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
		Initialize();
		while (true) {
			OnUpdate();
		}
		ShutDown();

	}
}