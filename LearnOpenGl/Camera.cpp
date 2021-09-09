#include "Camera.h"

Core::Camera::Camera(Vector3 position, Vector3 target, Vector3 worldUp)
{
	this->position = glm::vec3(position.x, position.y, position.z);
	glm::vec3 t = glm::vec3(target.x, target.y, target.z);
	this->worldUp = glm::vec3(worldUp.x, worldUp.y, worldUp.z);
	forward = glm::normalize(t - this->position);
	right = glm::normalize(glm::cross(forward, this->worldUp));
	up = glm::normalize(glm::cross(forward, right));
}

Core::Camera::Camera(Vector3 position, float yaw, float pitch, Vector3 worldUp)
{
	this->position = glm::vec3(position.x, position.y, position.z);
	this->worldUp = glm::vec3(worldUp.x, worldUp.y, worldUp.z);
	this->forward.x = glm::cos(pitch) * glm::sin(yaw);
	this->forward.y = glm::sin(pitch);
	this->forward.z = glm::cos(pitch) * glm::cos(yaw);
	this->right = glm::normalize(glm::cross(forward, this->worldUp));
	this->up = glm::normalize(glm::cross(forward, right));
}

Core::Camera::~Camera()
{
}

glm::mat4 Core::Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + forward, worldUp);
}
