#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "indexBuff.h"

indexBuff::indexBuff()
{
    unsigned int buffer;
    glCreateBuffers(1, &buffer);
    id = buffer;
}

indexBuff::indexBuff(unsigned int elemCount, unsigned int *data)
{
    unsigned int buffer;
    glCreateBuffers(1, &buffer);
    id = buffer;

    fill(elemCount, data);
}

indexBuff::~indexBuff()
{
    glDeleteBuffers(1, &id);
}

void indexBuff::fill(unsigned int elemCount, unsigned int *data)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(unsigned int), data,
                 GL_STATIC_DRAW);
}

void indexBuff::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void indexBuff::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int indexBuff::getId()
{
    return id;
}

