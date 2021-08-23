#include "MainRender.h"
#include <iostream>
#include "Shader.h"
#include "ImageLoad.h"

#include "Object.h"
#include "Transform.h"

namespace Render 
{
    float vertices[] = {
        //     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
        -0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.0f,    0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.1f, 0.2f, 0.8f,   1.0f, 0.0f,
         0.5f,  0.8f, 0.0f, 0.3f, 0.9f, 0.6f,   1.0f, 0.8f,
         -0.5f,  0.8f, 0.0f, 0.7f, 0.1f, 0.4f,   0.0f, 0.8f
    };

    float vertices2[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         -0.5f,  0.8f, 0.0f
    };

    unsigned int indices[] = { // 注意索引从0开始! 
        0, 1, 2, // 第一个三角形
        2, 3, 0  // 第二个三角形
    };

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout(location = 1) in vec3 aColor;\n" // 颜色变量的属性位置值为 1
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
        Object* o = new Object();
        Transform * transform = o->AddComponent<Transform>();
        transform->SetPosition(Vector3(0.1f, 0.1f, 0.1f));
        transform->SetRotate(Vector3(1.02f, 0.02f, 1.0f));
        transform->SetScale(Vector3(2.0f, 1.1f, 1.1f));

        unsigned int VAO;
        glGenVertexArrays(1, &VAO);  // 生成一个VAO， 将产生的VAO的坐标传给 VAO， 1为产生1个，VAO可以是数组去接
        glBindVertexArray(VAO);     // 使用这个VAO，绑定VAO到工作区

        unsigned int VBO;
        glGenBuffers(1, &VBO);      // 生成VBO vertex buffer objects
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  // 将GL_ARRAY_BUFFER 缓冲区 绑定到这个VBO上，之后再GL_ARRAY_BUFFER 这个缓冲区上的操作都将作用在这个 VBO上

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 往GL_ARRAY_BUFFER缓冲区添加 顶点列表


        unsigned int EBO;
        glGenBuffers(1, &EBO);      // 生成EBO Element Buffer Object

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // 将GL_ELEMENT_ARRAY_BUFFER 缓冲区 绑定到这个EBO上，之后再GL_ELEMENT_ARRAY_BUFFER 这个缓冲区上的操作都将作用在这个 VBO上
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);     // 往GL_ELEMENT_ARRAY_BUFFER缓冲区添加 顶点列表


        //unsigned int vertexShader;
        //vertexShader = glCreateShader(GL_VERTEX_SHADER);    // 创建一个shader, 一个顶点shader

        //glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 这个shader 绑定数据源
        //glCompileShader(vertexShader);  // 编译shader

        //// 判断shader是否正确
        //int  success;
        //char infoLog[512];
        //glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        //if (!success)
        //{
        //    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        //    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        //}

        //// 片源着色器
        //unsigned int fragmentShader;
        //fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        //glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        //glCompileShader(fragmentShader);


        //unsigned int shaderProgram;
        //shaderProgram = glCreateProgram();      // 创建一个程序，一个着色器处理程序

        //glAttachShader(shaderProgram, vertexShader);    // 顶点着色器
        //glAttachShader(shaderProgram, fragmentShader);
        //glLinkProgram(shaderProgram);   // 绑定

        //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        //if (!success) {
        //    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        //    std::cout << "ERROR::SHADER::PROGRAM_FAILED\n" << infoLog << std::endl;
        //}

        //glUseProgram(shaderProgram); // 激活这个程序

        //glDeleteShader(vertexShader);   // 已经连接到 program 里，现在不需要了
        //glDeleteShader(fragmentShader);

        Shader* shader = new Shader("/asserts/shaders/shader.vs", "/asserts/shaders/shader.fs");

        Image* image = ImageLoad::LoadImage("/asserts/images/Megane.png");

        // 顶点属性
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);   // 绑定顶点 0开始， 3个数据， float类型， 非规范化， 数据之间的间隔， 额外参数
        // 这时使用的数据是 当前 GL_ARRAY_BUFFER 缓冲区的数据
        glEnableVertexAttribArray(0);

        // 颜色属性
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // UV纹理
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glm::mat4 view = glm::mat4(1.0f);
        // 注意，我们将矩阵向我们要进行移动场景的反方向移动。
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720, 0.1f, 100.0f);

        while (!glfwWindowShouldClose(window)) {
            processInput(window);


            glClearColor(0, 0, 0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            glBindVertexArray(VAO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            float timeValue = glfwGetTime();
            float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
            /*int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
            glUseProgram(shaderProgram);
            glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);*/

            shader->use();
            shader->setFloat4("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
            shader->setInt("ourTexture", 0);
            shader->setMat4("model", transform->GetLocalMat4());
            shader->setMat4("view", view);
            shader->setMat4("projection", projection);

            image->use();

            // glDrawArrays(GL_TRIANGLES, 0, 3);

            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            glfwPollEvents();
            glfwSwapBuffers(window);
        }


        delete shader;

        return 0;
    }

    void MainRender::processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }
}
