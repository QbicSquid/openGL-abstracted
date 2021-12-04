#ifndef INDEXBUFF_H
#define INDEXBUFF_H

class indexBuff
{
    private:
        unsigned int id;
    public:
        indexBuff();
        indexBuff(unsigned int elemCount, unsigned int *data);
        ~indexBuff();
        void fill(unsigned int elemCount, unsigned int *data);
        void bind();
        void unbind();
        unsigned int getId();
};

#endif

