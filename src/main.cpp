#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "mgl.h"

int main()
{
    // initialize
    if(!glfwInit())
        return -1;

    GLFWwindow *window;
    window = glfwCreateWindow(640, 480, "abstracted", NULL, NULL);
    if(!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return -1;
    }

    // creating vertex buffer
    float positions[6] =
    {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f
    };

    vertexBuff buffer(6, positions);

    // enabling the vertext array element
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    std::cout << __LINE__ << std::endl;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}

