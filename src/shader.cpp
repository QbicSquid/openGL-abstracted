#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <fstream>
#include <sstream>
#include <iostream>

#include "shader.h"

shader::shader(std::string filepath)
{
    shaderSources shaderCode = parseShader(filepath);

    id = createShader(shaderCode.vertextSource,
            shaderCode.fragmentSource);
}

shaderSources shader::parseShader(const std::string filepath)
{
    std::ifstream stream(filepath);
    std::stringstream ss[2];

    enum class shaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    shaderType type= shaderType::NONE;
    std::string line;
    while(std::getline(stream, line))
    {
        if(line.find("#shader") != std::string::npos)
        {
            if(line.find("vertex") != std::string::npos)
                type = shaderType::VERTEX;
            else if(line.find("fragment") != std::string::npos)
                type = shaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }

    return {ss[0].str(), ss[1].str()};
}

unsigned int shader::compileShader(unsigned int type, const std::string &source)
{
    unsigned int shaderId = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);

    //Error Handling
    int result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

    if(result == GL_FALSE)
    {
        int length;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
        char *errmsg = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(shaderId, length, &length, errmsg);

        std::cout << "Failed to compile "
                  << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                  << " shader\n"
                  << errmsg
                  << std::endl;

        glDeleteShader(shaderId);
        return 0;
    }

    return shaderId;
}

unsigned int shader::createShader(const std::string &vertextShader,
                        const std::string &fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER,   vertextShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

void shader::bind()
{
    glUseProgram(id);
}

void shader::unbind()
{
    glUseProgram(0);
}

void shader::setUniform4f(const std::string name, float v0, float v1, float v2,
        float v3)
{
    unsigned int location = glGetUniformLocation(id, name.c_str());

    if(location == -1)
        std::cout << "shader/uniform not found\n";

    glUniform4f(location, v0, v1, v2, v3);
}

