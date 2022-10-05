//
// Created by Onuralp Sezer on 10/5/22.
//

#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window;
    if(!glfwInit())
        return -1;

    window = glfwCreateWindow(640,480,"OpenGlPlayground-window",nullptr,nullptr);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
