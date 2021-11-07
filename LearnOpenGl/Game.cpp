#include "Game.h"
#include "SceneManager.h"
#include "Camera.h"
#include "Scene.h"
#include "Object.h"

#include <stdio.h>

using namespace Core;

Game* Game::instance = nullptr;
GLFWwindow* Game::window = nullptr;

void Game::Tick(long time)
{
	delay = time;

	Scene* currScene = SceneManager::GetInstance()->GetCurrScene();
	Object* o = currScene->getObject();

	o->PreUpdate();
	o->Update();
	o->LaterUpdate();
}
