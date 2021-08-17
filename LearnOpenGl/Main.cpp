#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Main.h"
#include "MainRender.h"
#include <direct.h>
#include "FilePathManager.h"

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
    glEnable(GL_CULL_FACE);    // 剔除面
    glCullFace(GL_BACK);       // 剔除背面

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);  // 线框模式

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // 纹理为临近，即取最靠近这个点的像素数值


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   // 纹理为线性的，即取点和点附近的值进行运算

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Render::MainRender* render = new Render::MainRender();

    render->renderLoop(window);

    delete render;

    glfwTerminate();

    return 0;
}

// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

