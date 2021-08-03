#include "Main.h"
#include "MainRender.h"

int main(int argc, char* argv[])
{
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

