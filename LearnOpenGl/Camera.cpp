#include "Camera.h"

using namespace Core;
Core::Camera::Camera()
{
	this->position = Vector3(0, 0, 0);
	this->worldUp = Vector3(0, 0, 0);
	forward = Vector3(0, 0, 1);
	right = Vector3(1, 0, 0);
	up = Vector3(0, 1, 0);
	change = true;
}

Core::Camera::~Camera()
{
}

void Core::Camera::initPos(Vector3 position, Vector3 target, Vector3 worldUp)
{
	this->position = Vector3(position.x, position.y, position.z);
	glm::vec3 t = Vector3(target.x, target.y, target.z);
	this->worldUp = Vector3(worldUp.x, worldUp.y, worldUp.z);
	forward = glm::normalize(t - this->position);
	right = glm::normalize(glm::cross(forward, this->worldUp));
	up = glm::normalize(glm::cross(forward, right));
	change = true;
}

void Core::Camera::initPos(Vector3 position, float yaw, float pitch, Vector3 worldUp)
{
	this->position = Vector3(position.x, position.y, position.z);
	this->worldUp = Vector3(worldUp.x, worldUp.y, worldUp.z);
	this->forward.x = glm::cos(pitch) * glm::sin(yaw);
	this->forward.y = glm::sin(pitch);
	this->forward.z = glm::cos(pitch) * glm::cos(yaw);
	this->right = glm::normalize(glm::cross(forward, this->worldUp));
	this->up = glm::normalize(glm::cross(forward, right));
	change = true;
}

void Core::Camera::calcViewMatrix()
{
	this->lookAt = glm::lookAt(position, position + forward, worldUp);
}

glm::mat4 Core::Camera::GetViewMatrix()
{
	if (change) {
		calcViewMatrix();
	}
	return this->lookAt;
}

void Camera::SetMainCamera(bool iaMain)
{

}