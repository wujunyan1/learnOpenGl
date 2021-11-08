#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Main.h"
#include "MainRender.h"
#include <direct.h>
#include "FilePathManager.h"
#include "Game.h"
#include "Input.h"
#include "Core.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


int main(int argc, char* argv[])
{
    char buffer[64];
    char* c = _getcwd(buffer, 64);

    printf(c);
    FilePathManager::setRootPath(buffer);

    glfwInit();
    glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Learn OpenGL", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    glewExperimental = true;

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, 1280, 720);
    //glEnable(GL_CULL_FACE);    // 剔除面
    //glCullFace(GL_BACK);       // 剔除背面
    glEnable(GL_DEPTH_TEST);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // 线框模式

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // 纹理为临近，即取最靠近这个点的像素数值


    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 1280.0f / 720, 0.1f, 100.0f);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   // 纹理为线性的，即取点和点附近的值进行运算

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);    // 鼠标箭头隐藏

    glfwSetCursorEnterCallback(window, mouse_enter_callback);
    glfwSetCursorPosCallback(window, mouse_pos_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetKeyCallback(window, key_callback);

    Core::Game* game = Core::Game::GetInstance();
    Render::MainRender* render = new Render::MainRender();
    game->SetWindow(window);


    render->renderLoop(window);


    delete render;
    Core::Game::DestroyInstance();

    glfwTerminate();

    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    /*if (action != GLFW_PRESS)
        return;
    switch (key)
    {
    case GLFW_KEY_ESCAPE:
        glfwSetWindowShouldClose(window, GL_TRUE);
        break;
    default:
        break;
    }*/

    if (action == GLFW_PRESS)
        Core::Input::keys[key] = true;
    else if (action == GLFW_RELEASE)
        Core::Input::keys[key] = false;
}

void mouse_enter_callback(GLFWwindow* window, int index)
{

}

void mouse_pos_callback(GLFWwindow* window, double x, double y)
{
    Core::Input::mousePos = Core::Vector2(x, y);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
        Core::Input::keys[button] = true;
    else if (action == GLFW_RELEASE)
        Core::Input::keys[button] = false;
}

// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}