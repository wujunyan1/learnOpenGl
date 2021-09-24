#pragma once
#include "Camera.h"


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

		Camera GetMainCamera() { return mainCamera; }

	private:
		static Game* instance;

		Game() 
		{
		}

		Camera mainCamera = Camera(Vector3(0.0f, 0.0f, -4.0f), 0, 0, Vector3(0.0f, 1.0f, 0.0f));
	};
}

