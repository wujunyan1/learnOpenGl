#include "PointLight.h"
#include "SceneManager.h"
#include "Scene.h"

using namespace Logic;

void PointLight::Bind() 
{
	Core::Scene* scene = Core::SceneManager::GetInstance()->GetCurrScene();

	scene->setPointLight(*this);
}