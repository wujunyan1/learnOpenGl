#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void mouse_enter_callback(GLFWwindow* window, int index);

void mouse_pos_callback(GLFWwindow* window, double x, double y);

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

// 窗口大小发生变化
void framebuffer_size_callback(GLFWwindow* window, int width, int height);