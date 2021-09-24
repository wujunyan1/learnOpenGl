#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouse_enter_callback(GLFWwindow* window, int index);

void mouse_pos_callback(GLFWwindow* window, double x, double y);

// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height);