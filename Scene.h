#ifndef SCENE_H
#define SCENE_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include <vector>
#include "Object.h"

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

        protected:

            std::vector<Object*> m_objects;


        private:
    };
}
#endif // SCENE_H
