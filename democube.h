#ifndef _DEMO_CUBE_H_
#define _DEMO_CUBE_H_

#include "demo.h"

#include <glm/gtc/matrix_transform.hpp>

class DemoCube: public Demo {
    public:
        DemoCube();

        void Init();
        void Update();

    private:
        GLuint vertexArrayID;
        GLuint vertexBuffer;
        GLuint colorBuffer;

        GLuint program;
        GLfloat* vertexBufferData;
        GLfloat* colorBufferData;
    
        glm::mat4 projection;
        glm::mat4 view;
        glm::mat4 model;
};

#endif
