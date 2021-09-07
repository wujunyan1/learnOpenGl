#include "Camera.h"

Core::Camera::Camera(Vector3 position, Vector3 target, Vector3 worldUp)
{
	Position = glm::vec3(position.x, position.y, position.z);
	glm::vec3 t = glm::vec3(target.x, target.y, target.z);
	WorldUp = glm::vec3(worldUp.x, worldUp.y, worldUp.z);
	Forward = glm::normalize(t - Position);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));

}

Core::Camera::~Camera()
{
}

glm::mat4 Core::Camera::GetViewMatrix()
{
	return glm::lookAt(Position, Position + Forward, WorldUp);
}
