#ifndef VERTEXBUFF_H
#define VERTEXBUFF_H

unsigned int func(unsigned int elemCount, void *data);

class vertexBuff
{
    private:
        unsigned int id;
    public:
        vertexBuff();
        vertexBuff(unsigned int size, float *data);
        ~vertexBuff();
        void fill(unsigned int size, float *data);
        void bind();
        void unbind();
        unsigned int getId();
};

#endif

