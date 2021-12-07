#ifndef SHADER_H
#define SHADER_H

#include <string>

struct shaderSources
{
    std::string vertextSource;
    std::string fragmentSource;
};

class shader
{
    private:
        unsigned int id;

        shaderSources parseShader(const std::string filepath);
        unsigned int compileShader(unsigned int type,
                const std::string &source);
        unsigned int createShader(const std::string &vertextShader,
                const std::string &fragmentShader);

    public:
        shader(std::string filepath);
        void setUniform4f(const std::string name, float v0, float v1,
                float v2, float v3);
        void bind();
        void unbind();
};

#endif

