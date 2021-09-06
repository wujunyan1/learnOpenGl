#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <time.h>    

namespace Render
{
	class MainRender
	{
	public:
		MainRender() {
		};
		int renderLoop(GLFWwindow* window);

		long getCurrentTime()  {
			return clock();
		}

	private:
		void processInput(GLFWwindow* window);

	private:
	};
}

