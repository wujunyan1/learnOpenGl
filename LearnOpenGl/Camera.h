#pragma once
#include "Object.h"
#include "Core.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Component.h"

namespace Core
{
	class Camera : public Component
	{
	public:
		Camera();
		void initPos(Vector3 position, Vector3 target, Vector3 worldUp);
		void initPos(Vector3 position, float yaw, float pitch, Vector3 worldUp);
		~Camera();

		glm::mat4 GetViewMatrix();

		void Init() {};
		void OnDestroy() {};

		void Bind() {}
		void UnBind() {}
		void PreUpdate() {}
		void Update() {}
		void LaterUpdate() {}

	private:
		void calcViewMatrix();

	private:
		Vector3 position;
		Vector3 forward;
		Vector3 right;
		Vector3 up;
		Vector3 worldUp;

		bool change = false;
		Mat4 lookAt;
	};
}