#include "myEngine.h"
#include <iostream>
class MyGame : public Engine::EngineApp 
{
	// define own update method
	virtual void OnUpdate() override //add override to show it a new version of existing method
	{
		std::cout << "Engine is running" << std::endl;
	}
};

START_GAME(MyGame)

