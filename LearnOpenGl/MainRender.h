#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Render 
{
	class MainRender
	{
	public:
		int renderLoop(GLFWwindow* window);

	private:
		void processInput(GLFWwindow* window);
	};
}

