#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Context.h"
#include "MessageBus.h"
#include "Console.h"
#include "Ground.h"
#include "Clock.h"
#include "Scene.h"
#include "Cube.h"
#include "Camera.h"
#include "SkyBox.h"

using namespace Cagan;

bool QuitApp = false;

int main(int argc, char *argv[])
{
    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );

//    Cagan::Context* c = new Cagan::Context();
    Cagan::MessageBus* messageBus = new Cagan::MessageBus();
    Cagan::Console* console = new Cagan::Console(messageBus);
    Cagan::Ground* ground = new Cagan::Ground(30, 30);
    Cagan::Clock* clock = new Cagan::Clock();
    Cagan::Scene* scene = new Cagan::Scene();
    Cagan::Cube* cube = new Cagan::Cube();
    Cagan::Camera* camera = new Cagan::Camera(messageBus);
    Cagan::SkyBox* sky = new Cagan::SkyBox();

    scene->setCamera(camera);

//    ground->setSummitHeight(1, 1, 1.5);
//    ground->setSummitHeight(1, 2, 2);

    scene->init();
    scene->addObject(ground);
    scene->addObject(cube);
    scene->addObject(sky);

   // Dessiner();

    unsigned int ellapsed_time = clock->getEllapsed();

    while (!QuitApp)
    {

        scene->draw();
        scene->update(ellapsed_time);

        messageBus->notify();

        ellapsed_time = clock->getEllapsed();

        if (ellapsed_time < 16)
        {
            SDL_Delay(16 - ellapsed_time);
        }

    }


    return 0;

}
