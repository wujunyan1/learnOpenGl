#pragma once
#include "Object.h"
#include "Vector3.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core
{
	class Camera : Object
	{
	public:
		Camera(Vector3 position, Vector3 target, Vector3 worldUp);
		Camera(Vector3 position, float yaw, float pitch, Vector3 worldUp);
		~Camera();

		glm::mat4 GetViewMatrix();

	private:
		glm::vec3 position;
		glm::vec3 forward;
		glm::vec3 right;
		glm::vec3 up;
		glm::vec3 worldUp;
	};
}