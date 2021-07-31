#include "MainRender.h"
#include "iostream"

namespace Render 
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor; \n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \n"
        "}\0";

    int MainRender::renderLoop(GLFWwindow* window)
    {
        unsigned int VAO;
        glGenVertexArrays(1, &VAO);  // ����һ��VAO�� ��������VAO�����괫�� VAO�� 1Ϊ����1����VAO����������ȥ��
        glBindVertexArray(VAO);     // ʹ�����VAO����VAO��������

        unsigned int VBO;
        glGenBuffers(1, &VBO);      // ����VBO vertex buffer objects
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  // ��GL_ARRAY_BUFFER ������ �󶨵����VBO�ϣ�֮����GL_ARRAY_BUFFER ����������ϵĲ���������������� VBO��

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // ��GL_ARRAY_BUFFER��������� �����б�


        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);    // ����һ��shader, һ������shader

        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // ���shader ������Դ
        glCompileShader(vertexShader);  // ����shader

        // �ж�shader�Ƿ���ȷ
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // ƬԴ��ɫ��
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);


        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();      // ����һ������һ����ɫ���������

        glAttachShader(shaderProgram, vertexShader);    // ������ɫ��
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);   // ��

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM_FAILED\n" << infoLog << std::endl;
        }

        glUseProgram(shaderProgram); // �����������

        glDeleteShader(vertexShader);   // �Ѿ����ӵ� program ����ڲ���Ҫ��
        glDeleteShader(fragmentShader);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);   // �󶨶��� 0��ʼ�� 3�����ݣ� float���ͣ� �ǹ淶���� ����֮��ļ���� �������
        // ��ʱʹ�õ������� ��ǰ GL_ARRAY_BUFFER ������������
        glEnableVertexAttribArray(0);

        while (!glfwWindowShouldClose(window)) {
            processInput(window);


            glClearColor(0, 0, 0, 1.0);
            glClear(GL_COLOR_BUFFER_BIT);

            glBindVertexArray(VAO);
            glUseProgram(shaderProgram);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            glfwPollEvents();
            glfwSwapBuffers(window);
        }

        return 0;
    }

    void MainRender::processInput(GLFWwindow* window)
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }
}
