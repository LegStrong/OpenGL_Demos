#ifndef _Demo_H_
#define _Demo_H_


#include <GL/glew.h>

class Demo {
    public :
        Demo();

        virtual void Init();
        virtual void Update();
        virtual void OnResize(int w, int h);
};

#endif
