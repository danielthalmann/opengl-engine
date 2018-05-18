#ifndef CUBE_H
#define CUBE_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "Object.h"
#include "sdlglutils.h"

namespace Cagan
{
    class Cube : public Object
    {
        public:
            Cube();
            virtual ~Cube();
            void draw();
            void update(unsigned int ellapsed_time);
            void init();

        protected:
            float m_angleZ = 0;
            float m_angleX = 0;

            GLuint m_Texture;

        private:
    };
}
#endif // CUBE_H
