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
		~Camera();

		glm::mat4 GetViewMatrix();

	private:
		glm::vec3 Position;
		glm::vec3 Forward;
		glm::vec3 Right;
		glm::vec3 Up;
		glm::vec3 WorldUp;
	};
}