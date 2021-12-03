#include "Game.h"
#include "SceneManager.h"
#include "Object.h"
#include "Camera.h"
#include "Scene.h"
#include "Transform.h"
#include "CameraMove.h"
#include "Mesh.h"
#include "PointLight.h"

#include "Shader.h"
#include "ImageLoad.h"

#include <stdio.h>

using namespace Core;

Game* Game::instance = nullptr;
GLFWwindow* Game::window = nullptr;

Vector3 testVertices[] = {
    Vector3(-0.5f, -0.5f, -0.5f),
    Vector3(0.5f, -0.5f, -0.5f),
    Vector3(0.5f,  0.5f, -0.5f),
    Vector3(0.5f,  0.5f, -0.5f),
    Vector3(-0.5f,  0.5f, -0.5f),
    Vector3(-0.5f, -0.5f, -0.5f),

   Vector3(-0.5f, -0.5f,  0.5f),
   Vector3(0.5f, -0.5f,  0.5f),
   Vector3(0.5f,  0.5f,  0.5f),
   Vector3(0.5f,  0.5f,  0.5f),
   Vector3(-0.5f,  0.5f,  0.5f),
   Vector3(-0.5f, -0.5f,  0.5f),

   Vector3(-0.5f,  0.5f,  0.5f),
   Vector3(-0.5f,  0.5f, -0.5f),
   Vector3(-0.5f, -0.5f, -0.5f),
   Vector3(-0.5f, -0.5f, -0.5f),
   Vector3(-0.5f, -0.5f,  0.5f),
   Vector3(-0.5f,  0.5f,  0.5f),

   Vector3(0.5f,  0.5f,  0.5f),
   Vector3(0.5f,  0.5f, -0.5f),
   Vector3(0.5f, -0.5f, -0.5f),
   Vector3(0.5f, -0.5f, -0.5f),
   Vector3(0.5f, -0.5f,  0.5f),
   Vector3(0.5f,  0.5f,  0.5f),

   Vector3(-0.5f, -0.5f, -0.5f),
   Vector3(0.5f, -0.5f, -0.5f),
   Vector3(0.5f, -0.5f,  0.5f),
   Vector3(0.5f, -0.5f,  0.5f),
   Vector3(-0.5f, -0.5f,  0.5f),
   Vector3(-0.5f, -0.5f, -0.5f),

   Vector3(-0.5f,  0.5f, -0.5f),
   Vector3(0.5f,  0.5f, -0.5f),
   Vector3(0.5f,  0.5f,  0.5f),
   Vector3(0.5f,  0.5f,  0.5f),
   Vector3(-0.5f,  0.5f,  0.5f),
   Vector3(-0.5f,  0.5f, -0.5f),
};

Vector2 testUVs[] = {
    Vector2(0.0f, 0.0f),
    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 1.0f),
    Vector2(1.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 0.0f),

    Vector2(0.0f, 0.0f),
    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 1.0f),
    Vector2(1.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 0.0f),

    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 0.0f),
    Vector2(1.0f, 0.0f),

    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 1.0f),
    Vector2(0.0f, 0.0f),
    Vector2(1.0f, 0.0f),

    Vector2(0.0f, 1.0f),
    Vector2(1.0f, 1.0f),
    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 0.0f),
    Vector2(0.0f, 0.0f),
    Vector2(0.0f, 1.0f),

    Vector2(0.0f, 1.0f),
    Vector2(1.0f, 1.0f),
    Vector2(1.0f, 0.0f),
    Vector2(1.0f, 0.0f),
    Vector2(0.0f, 0.0f),
    Vector2(0.0f, 1.0f)
};


Vector3 testNormal[] = {
    Vector3(0.0f, 0.0f, -1.0f),
    Vector3(0.0f, 0.0f, -1.0f),
    Vector3(0.0f, 0.0f, -1.0f),
    Vector3(0.0f, 0.0f, -1.0f),
    Vector3(0.0f, 0.0f, -1.0f),
    Vector3(0.0f, 0.0f, -1.0f),

    Vector3(0.0f, 0.0f, 1.0f),
    Vector3(0.0f, 0.0f, 1.0f),
    Vector3(0.0f, 0.0f, 1.0f),
    Vector3(0.0f, 0.0f, 1.0f),
    Vector3(0.0f, 0.0f, 1.0f),
    Vector3(0.0f, 0.0f, 1.0f),

    Vector3(-1.0f, 0.0f, 0.0f),
    Vector3(-1.0f, 0.0f, 0.0f),
    Vector3(-1.0f, 0.0f, 0.0f),
    Vector3(-1.0f, 0.0f, 0.0f),
    Vector3(-1.0f, 0.0f, 0.0f),
    Vector3(-1.0f, 0.0f, 0.0f),

    Vector3(1.0f, 0.0f, 0.0f),
    Vector3(1.0f, 0.0f, 0.0f),
    Vector3(1.0f, 0.0f, 0.0f),
    Vector3(1.0f, 0.0f, 0.0f),
    Vector3(1.0f, 0.0f, 0.0f),
    Vector3(1.0f, 0.0f, 0.0f),

    Vector3(0.0f, -1.0f, 0.0f),
    Vector3(0.0f, -1.0f, 0.0f),
    Vector3(0.0f, -1.0f, 0.0f),
    Vector3(0.0f, -1.0f, 0.0f),
    Vector3(0.0f, -1.0f, 0.0f),
    Vector3(0.0f, -1.0f, 0.0f),

    Vector3(0.0f, 1.0f, 0.0f),
    Vector3(0.0f, 1.0f, 0.0f),
    Vector3(0.0f, 1.0f, 0.0f),
    Vector3(0.0f, 1.0f, 0.0f),
    Vector3(0.0f, 1.0f, 0.0f),
    Vector3(0.0f, 1.0f, 0.0f),
};

void Game::Tick(long time)
{
	delay = time;

	Scene* currScene = SceneManager::GetInstance()->GetCurrScene();
	Object* o = currScene->getObject();

	o->PreUpdate();
	o->Update();
	o->LaterUpdate();
}


void Game::Render(long time)
{
	Scene* currScene = SceneManager::GetInstance()->GetCurrScene();
	Object* o = currScene->getObject();

	o->Render();
}

void Game::LoadMainScene()
{
    Scene* scene = SceneManager::GetInstance()->GetCurrScene();
    scene->PreUpdate();
    scene->Update();
    scene->LaterUpdate();

    Core::Transform* root = scene->getObject()->GetComponent<Core::Transform>();

    Core::Object* o = ObjectManager::createNewObject();
    Core::Transform* transform = o->AddComponent<Core::Transform>();
    transform->SetPosition(Vector3(0.0f, 0.0f, -3.0f));
    transform->SetRotate(Vector3(0.0f, 0.0f, 0.0f));
    transform->SetScale(Vector3(1.0f, 1.0f, 1.0f));

    Core::Camera* camera = o->AddComponent<Core::Camera>();
    root->AddChild(transform);
    scene->setMainCamera(*camera);
    camera->initWorldUp(Vector3(0, 1, 0));

    o->AddComponent<Logic::CameraMove>();


    Core::Object* lightObj = ObjectManager::createNewObject();
    Core::Transform* lightTransform = lightObj->AddComponent<Core::Transform>();
    lightTransform->SetPosition(Vector3(0.0, 2.0f, 0.0f));
    root->AddChild(lightTransform);

    Logic::PointLight* light = lightObj->AddComponent<Logic::PointLight>();


    Core::Mesh* lightMesh = lightObj->AddComponent<Core::Mesh>();
    lightMesh->SetVertices(testVertices);
    lightMesh->SetUVs(testUVs);
    lightMesh->SetNormals(testNormal);

    Shader* test_light_shader = new Shader("/asserts/shaders/ambientLight.vert", "/asserts/shaders/ambientLight.frag");
    Image* test_light_image = ImageLoad::LoadImage("/asserts/images/container.jpg");
    lightMesh->SetShader(test_light_shader);
    lightMesh->SetImage(test_light_image, 0);
    lightMesh->bindRender();

    for (size_t i = 0; i < 10; i++)
    {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        int z = rand() % 10 + 1;

        Core::Object* o2 = ObjectManager::createNewObject();
        Core::Transform* transform2 = o2->AddComponent<Core::Transform>();
        root->AddChild(transform2);

        transform2->SetPosition(Vector3(x, y, z));
        transform2->SetRotate(Vector3(0.0f, 0.0f, 0.0f));
        Core::Mesh* mesh = o2->AddComponent<Core::Mesh>();
        mesh->SetVertices(testVertices);
        mesh->SetUVs(testUVs);
        mesh->SetNormals(testNormal);

        Shader* test_shader = new Shader("/asserts/shaders/shader.vert", "/asserts/shaders/shader.frag");
        Image* test_image = ImageLoad::LoadImage("/asserts/images/container.jpg");
        mesh->SetShader(test_shader);
        mesh->SetImage(test_image, 0);
        mesh->bindRender();
    }
}