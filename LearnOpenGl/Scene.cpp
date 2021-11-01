#include "Scene.h"
#include "Camera.h"

using namespace Core;

Camera Core::Scene::getMainCamera()
{
    return Camera();
}

void Core::Scene::setMainCamera(Camera camera)
{
    this->mainCamera = camera;
}