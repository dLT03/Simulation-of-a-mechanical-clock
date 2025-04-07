#include "Visualisation.h"
#include "Mechanism.h"
#include "Sound.h"
#include "WindowSetup.h"
#include <chrono>

int main(int argc, char* argv[])
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1200, 900, "clock", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    setPerspective(60.0f, (float)width / (float)height, 0.1f, 100.0f);

    glEnable(GL_DEPTH_TEST);

    float omega = 0.0f;

    glfwSetKeyCallback(window, keyCallback);

 
    if (!initializeSDLAudio()) {
        return -1;
    }
    Mix_Chunk* tickSound = loadTickSound();
    if (tickSound == NULL) {
        cleanupSDLAudio();
        return -1;
    }

    //chrono do œledzenia czasu
    auto lastTick = std::chrono::high_resolution_clock::now();

    while (!glfwWindowShouldClose(window)) {

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (perspectiveView) {
            setPerspective(57.0f, (float)width / (float)height, 0.1f, 100.0f);
            glLoadIdentity();
            glTranslatef(0.0f, 0.0f, cameraZ); 
        }
        else {
            setPerspective(57.0f, (float)width / (float)height, 0.1f, 100.0f);
            glLoadIdentity();
            gluLookAt(0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0); 
        }
        glRotatef(angle, 0.0f, 1.0f, 0.0f); 

        if (visualizationMode == 1) {
            Visualisation(0);
        }
        else if (visualizationMode == 2) {
            Mechanizm(omega);
        }

        omega += 0.0001f;

        // czy minê³a jedna sekunda od ostatniego odtworzenia dŸwiêku
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastTick).count();
        if (duration >= 1000) {
            playTickSound(tickSound);
            lastTick = now;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Mix_FreeChunk(tickSound);
    cleanupSDLAudio();

    glfwTerminate();
    return 0;
}
