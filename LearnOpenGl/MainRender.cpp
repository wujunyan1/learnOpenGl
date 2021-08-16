#include "MainRender.h"
#include <iostream>
#include "Shader.h"

namespace Render 
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.5f, 0.5f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.1f, 0.2f, 0.8f,
         0.5f,  0.5f, 0.0f, 0.3f, 0.9f, 0.6f,
         -0.5f,  0.8f, 0.0f, 0.7f, 0.1f, 0.4f
    };

    float vertices2[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         -0.5f,  0.8f, 0.0f
    };

    unsigned int indices[] = { // ע��������0��ʼ! 
        0, 1, 2, // ��һ��������
        2, 3, 0  // �ڶ���������
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
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);  // ����һ��VAO�� ��������VAO�����괫�� VAO�� 1Ϊ����1����VAO����������ȥ��
        glBindVertexArray(VAO);     // ʹ�����VAO����VAO��������

        unsigned int VBO;
        glGenBuffers(1, &VBO);      // ����VBO vertex buffer objects
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  // ��GL_ARRAY_BUFFER ������ �󶨵����VBO�ϣ�֮����GL_ARRAY_BUFFER ����������ϵĲ���������������� VBO��

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // ��GL_ARRAY_BUFFER���������� �����б�


        unsigned int EBO;
        glGenBuffers(1, &EBO);      // ����EBO Element Buffer Object

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // ��GL_ELEMENT_ARRAY_BUFFER ������ �󶨵����EBO�ϣ�֮����GL_ELEMENT_ARRAY_BUFFER ����������ϵĲ���������������� VBO��
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);     // ��GL_ELEMENT_ARRAY_BUFFER���������� �����б�


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

        Shader* shader = new Shader("/asserts/shaders/shader.vs", "/asserts/shaders/shader.fs");

        // ��������
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);   // �󶨶��� 0��ʼ�� 3�����ݣ� float���ͣ� �ǹ淶���� ����֮��ļ���� �������
        // ��ʱʹ�õ������� ��ǰ GL_ARRAY_BUFFER ������������
        glEnableVertexAttribArray(0);

        // ��ɫ����
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

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