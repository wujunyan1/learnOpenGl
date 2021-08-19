#pragma once
#include "Vector3.h"
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform : Component
{
public:
	Transform() {
		position = Vector3();
		scale = Vector3();
		rotate = Vector3();

		localMat4 = glm::mat4(1.0f);
		worldMat4 = glm::mat4(1.0f);
	}

private :
	Vector3 position;
	Vector3 scale;
	Vector3 rotate;

	glm::mat4 localMat4;
	glm::mat4 worldMat4;
};

