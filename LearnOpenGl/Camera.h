#pragma once
#include "Object.h"
#include "Core.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Component.h"
#include "Transform.h"

namespace Core
{
	class Camera : public Component
	{
	public:
		Camera();
		void initWorldUp(Vector3 worldUp);
		void initPos(Vector3 position, float yaw, float pitch, Vector3 worldUp);
		~Camera();

		glm::mat4 GetViewMatrix();

		void SetMainCamera(bool iaMain);

		void Init() {};
		void OnDestroy() {};

		void Bind();
		void UnBind() {}
		void PreUpdate() {}
		void Update() {}
		void LaterUpdate() {}

	private:
		void calcViewMatrix();

	private:
		Transform* tramsform;
		Vector3 worldUp;
		Vector3 forward;

		bool change = false;
		Mat4 lookAt;
	};
}