#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "mgl.h"

unsigned int func(unsigned int elemCount, void *data)
{
    unsigned int buffer;
    glCreateBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    float positions[6] =
    {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f
    };

    glBufferData(GL_ARRAY_BUFFER, elemCount * sizeof(float), data,
                 GL_STATIC_DRAW);

    return buffer;
}


vertexBuff::vertexBuff()
{
    unsigned int buffer;
    glCreateBuffers(1, &buffer);
    id = buffer;
}

vertexBuff::vertexBuff(unsigned int elemCount, float *data)
{
    unsigned int buffer;
    glCreateBuffers(1, &buffer);
    id = buffer;

    fill(elemCount, data);
}

vertexBuff::~vertexBuff()
{
    glDeleteBuffers(1, &id);
}

void vertexBuff::fill(unsigned int elemCount, float *data)
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, elemCount * sizeof(float), data,
                 GL_STATIC_DRAW);
}

void vertexBuff::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void vertexBuff::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int vertexBuff::getId()
{
    return id;
}

