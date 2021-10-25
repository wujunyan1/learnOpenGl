#pragma once

#include "Scene.h"

namespace Core 
{
	class SceneManager
	{
	public:
		static SceneManager* GetInstance() {
			if (instance == nullptr) {
				instance = new SceneManager();
			}
			return instance;
		}
	private:
		SceneManager() {
			root = new Object();
			root->AddComponent<Transform>();
		}

	private:
		static SceneManager* instance;

		Object* root;
	};

}

