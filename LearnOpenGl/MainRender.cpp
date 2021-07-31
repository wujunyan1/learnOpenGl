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
        glGenVertexArrays(1, &VAO);  // 生成一个VAO， 将产生的VAO的坐标传给 VAO， 1为产生1个，VAO可以是数组去接
        glBindVertexArray(VAO);     // 使用这个VAO，绑定VAO到工作区

        unsigned int VBO;
        glGenBuffers(1, &VBO);      // 生成VBO vertex buffer objects
        glBindBuffer(GL_ARRAY_BUFFER, VBO);  // 将GL_ARRAY_BUFFER 缓冲区 绑定到这个VBO上，之后再GL_ARRAY_BUFFER 这个缓冲区上的操作都将作用在这个 VBO上

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // 往GL_ARRAY_BUFFER缓冲区添加 顶点列表


        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);    // 创建一个shader, 一个顶点shader

        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL); // 这个shader 绑定数据源
        glCompileShader(vertexShader);  // 编译shader

        // 判断shader是否正确
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // 片源着色器
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);


        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();      // 创建一个程序，一个着色器处理程序

        glAttachShader(shaderProgram, vertexShader);    // 顶点着色器
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);   // 绑定

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM_FAILED\n" << infoLog << std::endl;
        }

        glUseProgram(shaderProgram); // 激活这个程序

        glDeleteShader(vertexShader);   // 已经连接到 program 里，现在不需要了
        glDeleteShader(fragmentShader);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);   // 绑定顶点 0开始， 3个数据， float类型， 非规范化， 数据之间的间隔， 额外参数
        // 这时使用的数据是 当前 GL_ARRAY_BUFFER 缓冲区的数据
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
