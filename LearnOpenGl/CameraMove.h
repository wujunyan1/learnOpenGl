#pragma once
#include "Component.h"
#include "Core.h"

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
		Core::Vector2 preMousePos = Core::Vector2();
		bool isTouchDown = false;
	};
}

