#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>

#include "Game.h"

namespace Render
{
	class MainRender
	{
	public:
		MainRender() {
			game = Core::Game::GetInstance();
		};
		int renderLoop(GLFWwindow* window);

		long getCurrentTime()  {
			return clock();
		}

	private:
		void processInput(GLFWwindow* window);

	private:

        int frame = 0, time = 0, timebase = 0;
		void ShowFrameRate();

		Core::Game* game;
	};
}

