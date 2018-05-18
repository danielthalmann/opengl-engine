#ifndef SKYBOX_H
#define SKYBOX_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "Camera.h"
#include "Object.h"
#include "sdlglutils.h"

namespace Cagan
{
    class SkyBox : public Object, public IMessageReceiver
    {
        public:
            SkyBox();
            virtual ~SkyBox();
            void draw();
            void update(unsigned int ellapsed_time);
            void init();
            void setCamera(Camera* camera);

            void handleMessage(Message* message);

        protected:
            float m_width;
            float m_height;

            GLuint m_Textures[5];

        private:
    };
}
#endif // SKYBOX_H
