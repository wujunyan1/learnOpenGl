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


Logic::PointLight Scene::getPointLight()
{
    return this->pointlight;
}
void Scene::setPointLight(Logic::PointLight pointlight)
{
    this->pointlight = pointlight;
}