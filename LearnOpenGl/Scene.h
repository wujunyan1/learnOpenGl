#pragma once
#include "Object.h"
#include "Transform.h"
#include "Camera.h"

namespace Core
{
	class Scene : public Component
	{
	public:
		Scene() {
			
		}

		void Init() {};
		void OnDestroy() {};

		void Bind() {}
		void UnBind() {}
		void PreUpdate() {}
		void Update() {}
		void LaterUpdate() {}

		Camera getMainCamera();
		void setMainCamera(Camera camera);

	private:
		Camera mainCamera;
	};
}

