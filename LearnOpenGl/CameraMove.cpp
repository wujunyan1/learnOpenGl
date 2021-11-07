#include "CameraMove.h"
#include "Input.h"
#include "Game.h"
#include "Transform.h"
#include "Camera.h"

using namespace Logic;
using namespace Core;

void CameraMove::Update() {
    printf("CameraMove::Update \n");

	float delay = Core::Game::GetInstance()->GetCurrUpdateDelay();

    Transform* transform = getObject()->GetComponent<Transform>();
    Vector3 cameraPos = transform->GetPosition();
    Vector3 cameraFront = transform->getForword();

    Camera* camera = getObject()->GetComponent<Camera>();
    Vector3 cameraUp = camera->GetWorldUp();

    // ÉãÏñ»ú¿ØÖÆ
    float cameraSpeed = delay * moveSpeed;
    if (Core::Input::isKeyDown(Input::Key::W)) {
        cameraPos += cameraSpeed * cameraFront;
    }

    if (Core::Input::isKeyDown(Input::Key::S)) {
        cameraPos -= cameraSpeed * cameraFront;
    }
    if (Core::Input::isKeyDown(Input::Key::A)){
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }
    if (Core::Input::isKeyDown(Input::Key::D)){
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

    transform->SetPosition(cameraPos);
}