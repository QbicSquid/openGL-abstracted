#ifndef MGL_H
#define MGL_H

unsigned int func(unsigned int elemCount, void *data);

class parts
{

};

class vertexBuff
{
    private:
        unsigned int id;
    public:
        vertexBuff();
        vertexBuff(unsigned int elemCount, float *data);
        ~vertexBuff();
        void fill(unsigned int elemCount, float *data);
        void bind();
        void unbind();
        unsigned int getId();
};

#endif

