#include "BasicGame.h"

BasicGame::BasicGame()
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	for (int i = 0; i < 10; i++) {
		CreateEnemy();
	}
	currentX = 10;
	currentY = 10;
	currentSprite = new Engine::Unit("..\\Assets\\Textures\\sprite.png",currentX,currentY);
}

void BasicGame::DrawCurrentImage(Engine::Image* currentImage, int x, int y)
{
	Engine::Renderer::Draw(*currentImage, x, y);
}

void BasicGame::DrawCurrentImage(Engine::Unit* unit)
{
	Engine::Renderer::Draw(*unit);

}

void BasicGame::Run()
{
	Engine::EngineApp::Run();
}

void BasicGame::OnUpdate()
{
	keyChange();
	DrawCurrentImage(currentSprite);
	if (currentSprite->GetXCoord() < 0) currentSprite->SetCoords(0, currentSprite->GetYCoord());
	if (currentSprite->GetYCoord() < 0) currentSprite->SetCoords(currentSprite->GetXCoord(), 0);
	if (currentSprite->GetXCoord() >= Engine::EngineWindow::GetWindow()->GetWidth()) currentSprite->SetCoords(Engine::EngineWindow::GetWindow()->GetWidth() - 50, currentSprite->GetYCoord());
	if (currentSprite->GetYCoord() >= Engine::EngineWindow::GetWindow()->GetHeight()) currentSprite->SetCoords(currentSprite->GetXCoord(),Engine::EngineWindow::GetWindow()->GetHeight() - 50);
	DrawEnemies();
	CheckIntersection();
	if (isDead) {
		ShutDown();
	}

}

void BasicGame::ShutDown()
{
	gameOver = new Engine::Image("..\\Assets\\Textures\\over.png");
	int width = (Engine::EngineWindow::GetWindow()->GetWidth()) / 20.0;
	int height = Engine::EngineWindow::GetWindow()->GetHeight() / 20.0;
	allEnemies.clear();
	DrawCurrentImage(gameOver, width, height);
}


void BasicGame::keyChange()
{
	Engine::EngineApp::SetKeyPressedCallback([&](const Engine::KeyPressed& e) {
		if (e.GetKeyCode() == HAPPY_KEY_RIGHT || e.GetKeyCode() == HAPPY_KEY_D) {
			currentSprite->UpdateXCoord(50);
		}
		if (e.GetKeyCode() == HAPPY_KEY_LEFT || e.GetKeyCode() == HAPPY_KEY_A) {
			currentSprite->UpdateXCoord(-50);
		}
		if (e.GetKeyCode() == HAPPY_KEY_DOWN || e.GetKeyCode() == HAPPY_KEY_S) {
			currentSprite->UpdateYCoord(-50);
		}
		if (e.GetKeyCode() == HAPPY_KEY_UP || e.GetKeyCode() == HAPPY_KEY_W) {
			currentSprite->UpdateYCoord(50);
		}
	});
}

void BasicGame::DrawEnemies()
{
	for (auto& enemy : allEnemies) {
		DrawCurrentImage(enemy);
	}

}

void BasicGame::CheckIntersection()
{
	for (auto& enemy : allEnemies) {
		if (Engine::UnitsOverlap(*currentSprite, *enemy)) {
			RemoveEnemy(*enemy);
			counter++;
			if (counter == 10)
				UpdateSprite(2);
			if (counter == 20)
				UpdateSprite(3);
			if (counter == 30)
				UpdateSprite(4);
			CreateEnemy();
		}
	}
}

void BasicGame::RemoveEnemy(Engine::Unit& unit)
{
	auto it = std::find(allEnemies.begin(), allEnemies.end(), &unit);
	allEnemies.erase(it);
}

void BasicGame::CreateEnemy()
{
	Engine::Image pic{ "..\\Assets\\Textures\\enemy.png" };
	Engine::Unit* ptr = new Engine::Unit("..\\Assets\\Textures\\enemy.png", std::rand() % (Engine::EngineWindow::GetWindow()->GetWidth() - pic.GetWidth()), std::rand() % (Engine::EngineWindow::GetWindow()->GetHeight() - pic.GetHeight()));
	allEnemies.push_back({ ptr });
}

void BasicGame::UpdateSprite(int spriteNum)
{
	int currX = currentSprite->GetXCoord();
	int currY = currentSprite->GetYCoord();
	switch (spriteNum) {
	case 2:
		currentSprite = new Engine::Unit("..\\Assets\\Textures\\sprite2.png", currX, currY);
		break;
	case 3:
		currentSprite = new Engine::Unit("..\\Assets\\Textures\\sprite3.png", currX, currY);
		break;
	case 4:
		currentSprite = new Engine::Unit("..\\Assets\\Textures\\dead.png", currX, currY);
		isDead = true;
		break;
	}
}

bool BasicGame::CheckDead()
{
	return isDead;
}



