#pragma once
#include "Libraries.h"


//ustawienia kamery
float cameraZ = -5.0f;
float angle = 0.0f;
bool perspectiveView = true;
int visualizationMode = 1;

void setPerspective(float fov, float aspect, float near, float far)
{
    float f = 1.0f / tan(fov * 0.5f * 3.14159265359f / 180.0f);
    float matrix[16] =
    {
        f / aspect, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, (far + near) / (near - far), -1.0f,
        0.0f, 0.0f, (2.0f * far * near) / (near - far), 0.0f
    };

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(matrix);
    glMatrixMode(GL_MODELVIEW);
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    const float cameraSpeed = 0.1f;

    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_UP:
            cameraZ += cameraSpeed;
            break;
        case GLFW_KEY_DOWN:
            cameraZ -= cameraSpeed;
            break;
        case GLFW_KEY_LEFT:
            angle += 1.0f;
            break;
        case GLFW_KEY_RIGHT:
            angle -= 1.0f;
            break;
        case GLFW_KEY_P:
            perspectiveView = true;
            break;
        case GLFW_KEY_O:
            perspectiveView = false;
            break;
        case GLFW_KEY_1:
            visualizationMode = 1;
            break;
        case GLFW_KEY_2:
            visualizationMode = 2;
            break;

        }
    }
}
