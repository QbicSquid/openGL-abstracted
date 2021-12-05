#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "vertexBuff.h"
#include "indexBuff.h"
#include "shader.h"

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

    vertexBuff buffer(6 * sizeof(float), positions);

    // creating index buffer
    unsigned int indeces[3] =
    {
        0, 1, 2
    };

    indexBuff ibo(3, indeces);

    // enabling the vertext array element
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // creating shaders
    shader shader("../res/shaders/shaders.shader");
    shader.bind();

    std::cout << __LINE__ << std::endl;

    while(!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}

