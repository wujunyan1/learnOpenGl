#include "MainRender.h"
#include <iostream>
#include <cstdlib>

#include "Shader.h"
#include "ImageLoad.h"

#include "Object.h"
#include "Transform.h"
#include "Game.h"
#include "Camera.h"
#include "CameraMove.h"
#include "Mesh.h"

#include "SceneManager.h"

using namespace Render;
using namespace Core;

    float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };


    unsigned int indices[] = { // ע��������0��ʼ! 
        0, 1, 2, // ��һ��������
        2, 3, 0  // �ڶ���������
    };

    Vector3 cubePositions[] = {
      Vector3(0.0f,  0.0f,  0.0f),
      Vector3(2.0f,  5.0f, -15.0f),
      Vector3(-1.5f, -2.2f, -2.5f),
      Vector3(-3.8f, -2.0f, -12.3f),
      Vector3(2.4f, -0.4f, -3.5f),
      Vector3(-1.7f,  3.0f, -7.5f),
      Vector3(1.3f, -2.0f, -2.5f),
      Vector3(1.5f,  2.0f, -2.5f),
      Vector3(1.5f,  0.2f, -1.5f),
      Vector3(-1.3f,  1.0f, -1.5f)
        };

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



    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout(location = 1) in vec3 aColor;\n" // ��ɫ����������λ��ֵΪ 1
        "out vec4 vertexColor;\n"
        "uniform vec4 ourColor; \n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   vertexColor = vec4(aColor.x, aColor.y, aColor.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "in vec4 vertexColor;\n"
        "out vec4 FragColor; \n"
        "void main()\n"
        "{\n"
        "   FragColor = vertexColor; \n"
        "}\0";

    int MainRender::renderLoop(GLFWwindow* window)
    {
        
        Scene* scene = SceneManager::GetInstance()->GetCurrScene();
        scene->PreUpdate();
        scene->Update();
        scene->LaterUpdate();
        

        Core::Object* o = ObjectManager::createNewObject();
        Core::Transform * transform = o->AddComponent<Core::Transform>();
        transform->SetPosition(Vector3(0.0f, 0.0f, -3.0f));
        transform->SetRotate(Vector3(0.0f, 0.0f, 0.0f));
        transform->SetScale(Vector3(1.0f, 1.0f, 1.0f));

        Core::Camera* camera = o->AddComponent<Core::Camera>();
        scene->getObject()->GetComponent<Core::Transform>()->AddChild(transform);
        scene->setMainCamera(*camera);
        camera->initWorldUp(Vector3(0, 1, 0));

        o->AddComponent<Logic::CameraMove>();

        Core::Object* o2 = ObjectManager::createNewObject();
        Core::Transform* transform2 = o2->AddComponent<Core::Transform>();
        scene->getObject()->GetComponent<Core::Transform>()->AddChild(transform2);

        transform2->SetPosition(Vector3(0.0f, 0.0f, -10.0f));
        transform2->SetRotate(Vector3(1.0f, 1.0f, 0.5f));
        Core::Mesh* mesh = o2->AddComponent<Core::Mesh>();
        mesh->SetVertices(testVertices);
        mesh->SetUVs(testUVs);

        Shader* test_shader = new Shader("/asserts/shaders/shader.vs", "/asserts/shaders/shader.fs");
        Image* test_image = ImageLoad::LoadImage("/asserts/images/container.jpg");
        mesh->SetShader(test_shader);
        mesh->SetImage(test_image);
        mesh->bindRender();

        //Core::Camera carmera = game->GetMainCamera(); // (Vector3(0.0f, 0.0f, 3.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));


        //unsigned int VAO;
        //glGenVertexArrays(1, &VAO);  // ����һ��VAO�� ��������VAO�����괫�� VAO�� 1Ϊ����1����VAO����������ȥ��
        //glBindVertexArray(VAO);     // ʹ�����VAO����VAO��������

        //unsigned int VBO;
        //glGenBuffers(1, &VBO);      // ����VBO vertex buffer objects
        //glBindBuffer(GL_ARRAY_BUFFER, VBO);  // ��GL_ARRAY_BUFFER ������ �󶨵����VBO�ϣ�֮����GL_ARRAY_BUFFER ����������ϵĲ���������������� VBO��

        //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // ��GL_ARRAY_BUFFER���������� �����б�


        //unsigned int EBO;
        //glGenBuffers(1, &EBO);      // ����EBO Element Buffer Object

        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // ��GL_ELEMENT_ARRAY_BUFFER ������ �󶨵����EBO�ϣ�֮����GL_ELEMENT_ARRAY_BUFFER ����������ϵĲ���������������� VBO��
        //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);     // ��GL_ELEMENT_ARRAY_BUFFER���������� �����б�


        //unsigned int vertexShader;
        //vertexShader = glCreateShader(GL_VERTEX_SHADER);    // ����һ��shader, һ������shader

        //glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // ���shader ������Դ
        //glCompileShader(vertexShader);  // ����shader

        //// �ж�shader�Ƿ���ȷ
        //int  success;
        //char infoLog[512];
        //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        //if (!success)
        //{
        //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        //    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        //}

        //// ƬԴ��ɫ��
        //unsigned int fragmentShader;
        //fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        //glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        //glCompileShader(fragmentShader);


        //unsigned int shaderProgram;
        //shaderProgram = glCreateProgram();      // ����һ������һ����ɫ����������

        //glAttachShader(shaderProgram, vertexShader);    // ������ɫ��
        //glAttachShader(shaderProgram, fragmentShader);
        //glLinkProgram(shaderProgram);   // ��

        //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        //if (!success) {
        //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        //    std::cout << "ERROR::SHADER::PROGRAM_FAILED\n" << infoLog << std::endl;
        //}

        //glUseProgram(shaderProgram); // �����������

        //glDeleteShader(vertexShader);   // �Ѿ����ӵ� program ����ڲ���Ҫ��
        //glDeleteShader(fragmentShader);

        //Shader* shader = new Shader("/asserts/shaders/shader.vs", "/asserts/shaders/shader.fs");

        //Image* image = ImageLoad::LoadImage("/asserts/images/container.jpg");



        //// ��������
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);   // �󶨶��� 0��ʼ�� 3�����ݣ� float���ͣ� �ǹ淶���� ����֮��ļ���� �������
        //// ��ʱʹ�õ������� ��ǰ GL_ARRAY_BUFFER ������������
        //glEnableVertexAttribArray(0);

        //// ��ɫ����
        ///*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        //glEnableVertexAttribArray(1);*/

        //// UV����
        //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        //glEnableVertexAttribArray(1);

        //glm::mat4 view = camera->GetViewMatrix(); // glm::mat4(1.0f);
        //// ע�⣬���ǽ�����������Ҫ�����ƶ������ķ������ƶ���
        ////view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));


        //glm::mat4 projection = glm::mat4(1.0f);
        //projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720, 0.1f, 100.0f);

        //long time = getCurrentTime();

        //const int num = 1;
        //Vector3* v = new Vector3[num];
        //for (unsigned int i = 0; i < num; i++)
        //{
        //    v[i] = Vector3((rand() % 3000 - 1500) * 1.0f / 1000.0f, (rand() % 3000 - 1500) * 1.0f / 1000.0f, (rand() % 3000 - 3000) * 1.0f / 1000.0f);
        //}

        //Transform* shaderTransform = new Transform();

        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            processInput(window);


            glClearColor(0, 0, 0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            //glBindVertexArray(VAO);
            //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            //view = camera->GetViewMatrix();

            //shader->use();
            //shader->setFloat4("ourColor", 0.0f, 0.0f, 0.0f, 1.0f);
            //shader->setInt("ourTexture", 0);
            //shader->setMat4("view", view);
            //shader->setMat4("projection", projection);


            //const int length = sizeof(vertices) / sizeof(vertices[0]);
            //float vertices2[length * num];
            //float vertices3[length];
            //unsigned int index = 0;

            //float* vs = vertices2;

            //for (unsigned int i = 0; i < num; i++)
            //{
            //    shaderTransform->SetPosition(v[i]);
            //    shaderTransform->SetRotate(Vector3(1.02f, (float)glfwGetTime() * glm::radians(50.0f) + (i * 20), 1.0f));
            //    shader->setMat4("model", shaderTransform->GetLocalMat4());

            //    glm::mat4 mat4 = shaderTransform->GetLocalMat4();

            //    float* v3s = vertices3;
            //    for (unsigned int j = 0; j < length; j+=5)
            //    {
            //        glm::vec4 v4 = glm::vec4(vertices[j], vertices[j + 1], vertices[j + 2], 1);
            //        v4 = mat4 * v4;

            //        vertices3[j] = v4.x;
            //        vertices3[j + 1] = v4.y;
            //        vertices3[j + 2] = v4.z;
            //        vertices3[j + 3] = vertices[j + 3];
            //        vertices3[j + 4] = vertices[j + 4];
            //    }

            //    memcpy(vs, vertices3, sizeof(vertices3));
            //    //index = index + length;
            //    vs = vs + length;
            //    // glDrawArrays(GL_TRIANGLES, 0, 36);
            //}
            //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STREAM_DRAW); // ��GL_ARRAY_BUFFER���������� �����б�

            //glDrawArrays(GL_TRIANGLES, 0, 36 * num);

            //image->use();

            // glDrawArrays(GL_TRIANGLES, 0, 3);

            //glDrawArrays(GL_TRIANGLES, 0, 36);
            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            long currTime = getCurrentTime();
            Core::Game::GetInstance()->Tick(currTime - time);
            Core::Game::GetInstance()->Render(currTime - time);
            time = currTime;

            glfwPollEvents();
            glfwSwapBuffers(window);
            //ShowFrameRate();
        }


        //delete shader;

        return 0;
    }

    void MainRender::processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

    }

    void MainRender::ShowFrameRate()
    {
        char s[100] = { 0 };
        frame++;
        time = glfwGetTime();
        if (time - timebase >= 1) {
            printf("FPS:%4.2f \n",
                frame * 1.0 / (time - timebase));
            timebase = time;
            frame = 0;
        }
    }
