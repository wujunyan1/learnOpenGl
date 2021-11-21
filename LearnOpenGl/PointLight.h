#pragma once
#include "Component.h"
#include "Core.h"

namespace Logic {
	class PointLight : public Core::Component
	{
	public:
		void Init() {};
		void OnDestroy() {};

		void Bind();
		void UnBind() {}
		void PreUpdate() {}
		void Update() {};
		void LaterUpdate() {}

	public:
		float lightIntensity = 1.0f;
		Core::Vector3 lightColor = Core::Vector3(1.0f, 1.0f, 1.0f);
	};
}

