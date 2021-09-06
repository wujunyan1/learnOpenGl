#include "Game.h"
#include <stdio.h>

using namespace Core;

Game* Game::instance = nullptr;

void Game::Tick(long time)
{
	printf("%d\n ", time);
}
