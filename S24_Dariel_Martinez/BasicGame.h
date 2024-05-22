#pragma once
#include<iostream>
#include "myEngine.h"

class BasicGame: public Engine::EngineApp {
public:
	BasicGame();
	void DrawCurrentImage(Engine::Image* currentImage, int x, int y);
	void DrawCurrentImage(Engine::Unit* unit);
	void Run();
	virtual void OnUpdate() override;
	virtual void ShutDown() override;
	void keyChange();
	void DrawEnemies();
	void CheckIntersection();
	void RemoveEnemy(Engine::Unit& unit);
	void CreateEnemy();
	void UpdateSprite(int spriteNum);
	bool CheckDead();

private:
	Engine::Unit* currentSprite;
	int currentX;
	int currentY;
	std::vector<Engine::Unit*> allEnemies;
	int counter{ 0 };
	bool isDead{ false };
	Engine::Image* gameOver{nullptr};
};

START_GAME(BasicGame)
