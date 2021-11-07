#include "Camera.h"

using namespace Core;
Core::Camera::Camera()
{
	this->worldUp = Vector3(0, 0, 0);
	forward = Vector3(0, 0, 1);
	position = Vector3(0, 0, 0);
}

Core::Camera::~Camera()
{
}
void Core::Camera::Bind()
{
	tramsform = object->GetComponent<Transform>();
	forward = tramsform->getForword();
	position = tramsform->GetPosition();
	calcViewMatrix();
}

void Core::Camera::initWorldUp(Vector3 worldUp)
{
	this->worldUp = Vector3(worldUp.x, worldUp.y, worldUp.z);
	calcViewMatrix();
}

void Core::Camera::initPos(Vector3 position, float yaw, float pitch, Vector3 worldUp)
{
	/*this->position = Vector3(position.x, position.y, position.z);
	this->worldUp = Vector3(worldUp.x, worldUp.y, worldUp.z);
	this->forward.x = glm::cos(pitch) * glm::sin(yaw);
	this->forward.y = glm::sin(pitch);
	this->forward.z = glm::cos(pitch) * glm::cos(yaw);
	this->right = glm::normalize(glm::cross(forward, this->worldUp));
	this->up = glm::normalize(glm::cross(forward, right));
	change = true;*/
}

void Core::Camera::calcViewMatrix()
{
	position = tramsform->GetPosition();
	forward = tramsform->getForword();
	this->lookAt = glm::lookAt(position, position + forward, worldUp);
}

glm::mat4 Core::Camera::GetViewMatrix()
{
	Vector3 newForward = tramsform->getForword();
	if (newForward != forward || position != tramsform->GetPosition()) {
		calcViewMatrix();
	}
	return this->lookAt;
}

void Camera::SetMainCamera(bool iaMain)
{

}