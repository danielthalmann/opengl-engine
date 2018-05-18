#ifndef SCENE_H
#define SCENE_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <vector>

#include "Object.h"
#include "Camera.h"

namespace Cagan
{

    class Scene
    {
        public:
            Scene();
            virtual ~Scene();

			void addObject(Object* obj);
			void draw();
			void update(unsigned int ellapsed_time);
			void init();
			void setCamera(Camera* camera);

        protected:

            std::vector<Object*> m_objects;
            Camera* m_camera;
            int m_Width;
            int m_Height;

            bool m_FullScreen;
            unsigned int m_VMFlag;
            int m_Bpp;


            SDL_Surface *m_Screen;


        private:
    };
}
#endif // SCENE_H
