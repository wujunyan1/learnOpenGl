#include "CameraMove.h"
#include "Input.h"
#include "Game.h"
#include "Transform.h"
#include "Camera.h"

using namespace Logic;
using namespace Core;

void CameraMove::Update() {
	float delay = Core::Game::GetInstance()->GetCurrUpdateDelay();

    Transform* transform = getObject()->GetComponent<Transform>();
    Vector3 cameraPos = transform->GetPosition();
    Vector3 cameraFront = transform->getForword();

    Camera* camera = getObject()->GetComponent<Camera>();
    Vector3 cameraUp = camera->GetWorldUp();

    // 摄像机控制
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


    if (Core::Input::isMouseLeftDown(Input::Key::MOUSE_BUTTON_LEFT)) {
        if (!isTouchDown) {
            isTouchDown = true;
            preMousePos = Input::GetCurrMousePos();
        }
        Vector2 currMousePos = Input::GetCurrMousePos();

        float xoffset = currMousePos.x - preMousePos.x;
        float yoffset = preMousePos.y - currMousePos.y; // 注意这里是相反的，因为y坐标的范围是从下往上的
        preMousePos = currMousePos;

        float sensitivity = 0.01f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        Vector3 rotate = transform->GetRotate();

        rotate.y += xoffset;
        rotate.x -= yoffset;

        transform->SetRotate(rotate);
    }
    if (Core::Input::isMouseLeftUp(Input::Key::MOUSE_BUTTON_LEFT)) {
        isTouchDown = false;
    }

}