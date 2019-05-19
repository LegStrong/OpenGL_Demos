#include "shader.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string ReadAllText(const std::string path){
    std::string code;

    std::ifstream fs(path.c_str(), std::ios::in);

    if(fs.is_open()){
        std::stringstream buffer;
        buffer << fs.rdbuf();
        code = buffer.str();
        fs.close();
    }
    else{
        fprintf(stderr, "Open File %s failed.\n", path.c_str());
    }

    return code;
}

void CompileShader(GLuint shader, std::string src) {
    GLint res = GL_FALSE;
    int logLen;

    char const* srcPointer = src.c_str(); 
    int len = src.size();
    glShaderSource(shader, 1, &srcPointer, &len);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &res);
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLen);
    fprintf(stderr, "Compile status %d\n", GL_FALSE);
    if(logLen > 1) {
        char *info = new char[logLen +1];
        glGetShaderInfoLog(shader, logLen, NULL, info);

        fprintf(stderr, "Compile Shader Error: %s\n", info);
        delete info;
    }
}



GLuint LoadShaders(const char* vertexFilePath, const char* fragmentFilePath){

    fprintf(stdout, "LoadShaders: %s;\n %s", vertexFilePath, fragmentFilePath);
    //Create the shaders
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexShaderCode = ReadAllText(vertexFilePath);
    std::string fragementShaderCode = ReadAllText(fragmentFilePath);

    CompileShader(vertexShaderID, vertexShaderCode);
    CompileShader(fragmentShaderID, fragementShaderCode);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShaderID);
    glAttachShader(program, fragmentShaderID);
	glLinkProgram(program);

    GLint res = GL_FALSE;
    int logLen;
    glGetProgramiv(program, GL_LINK_STATUS, &res);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLen);

    if(logLen> 1) {
        char *info = new char[logLen +1];
        glGetProgramInfoLog(program, logLen, NULL, info);

        fprintf(stderr, "Link Shader Error: %s\n", info);
        delete info;
    }

    glDetachShader(program, vertexShaderID);
    glDetachShader(program, fragmentShaderID);

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);

    return program;
}
