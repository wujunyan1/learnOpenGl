#pragma once
#include "Camera.h"
#include "Scene.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Core {
	class Game
	{
	public:
		static Game* GetInstance() {
			if (instance == nullptr) {
				instance = new Game();
			}

			return instance;
		}

		static void DestroyInstance() {
			if (instance != nullptr) {
				delete instance;
				instance = nullptr;
			}
		}

		void Tick(long time);
		void Render(long time);

		Camera GetMainCamera() { return mainCamera; }

		void SetMainCamera(Camera c) { mainCamera = c; }
		void SetWindow(GLFWwindow* w) { window = w; }
		static GLFWwindow* GetWindow() { return window; }

		float GetCurrUpdateDelay() { return delay / 1000; }

		void LoadMainScene();

	private:
		static Game* instance;
		static GLFWwindow* window;

		Game() 
		{
			delay = 0.0f;
		}

		Camera mainCamera;
		float delay;
	};
}

