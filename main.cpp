#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <SDL2/SDL.h>
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
#include "Light.h"
#include "Mesh.h"

using namespace Cagan;

bool QuitApp = false;

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[])
{
    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );


    Cagan::Scene* scene = new Cagan::Scene();
    scene->init();

//    Cagan::Context* c = new Cagan::Context();
    Cagan::MessageBus* messageBus = new Cagan::MessageBus();
    Cagan::Console* console = new Cagan::Console();
    Cagan::Ground* ground = new Cagan::Ground(30, 30);
    Cagan::Clock* clock = new Cagan::Clock();
    Cagan::Cube* cube = new Cagan::Cube();
    Cagan::Camera* camera = new Cagan::Camera();
    camera->setPosition(V3f(3, 3, 3));
    Cagan::SkyBox* sky = new Cagan::SkyBox();
    sky->setPosition(V3f(3, 3, 3));
    Cagan::Mesh* mesh = new Cagan::Mesh(std::string("meshs/tree/pin.obj"));
    Cagan::Light* light = new Cagan::Light();

    light->setPosition(V3f(6,7,8));

    messageBus->addReceiver(camera);
    messageBus->addReceiver(console);
    messageBus->addReceiver(sky);

    scene->setCamera(camera);

//    ground->setSummitHeight(1, 1, 1.5);
//    ground->setSummitHeight(1, 2, 2);

    scene->addObject(light);
    scene->addObject(ground);
    scene->addObject(cube);
    scene->addObject(sky);
    scene->addObject(mesh);



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
