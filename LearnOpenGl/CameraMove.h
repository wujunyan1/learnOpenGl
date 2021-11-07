#pragma once
#include "Component.h"

namespace Logic 
{
	class CameraMove : public Core::Component
	{
	public:
		void Init() {};
		void OnDestroy() {};

		void Bind() {}
		void UnBind() {}
		void PreUpdate() {}
		void Update();
		void LaterUpdate() {}

	public:
		float moveSpeed = 5.0f;
	};
}

