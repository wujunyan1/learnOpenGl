#include "Scene.h"
#include "Camera.h"

using namespace Core;

Camera Core::Scene::getMainCamera()
{
    return this->mainCamera;
}

void Core::Scene::setMainCamera(Camera camera)
{
    this->mainCamera = camera;
}