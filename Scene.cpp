#include "Scene.h"

using namespace Cagan;

Scene::Scene()
{
    //ctor
}

Scene::~Scene()
{
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Scene::addObject(Object* obj)
{
    m_objects.push_back(obj);
}

void Scene::draw()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );

    for (std::vector<Object*>::iterator iter = m_objects.begin(); iter != m_objects.end(); iter++) {

        glLoadIdentity( );
        gluLookAt(3,4,2,0,0,0,0,0,1);

        (*iter)->draw();
    }
}

void Scene::update(unsigned int ellapsed_time)
{
    for (std::vector<Object*>::iterator iter = m_objects.begin(); iter != m_objects.end(); iter++) {
        (*iter)->update(ellapsed_time);
    }
}

void Scene::init()
{

    SDL_Init(SDL_INIT_VIDEO);

    atexit(SDL_Quit);

    SDL_WM_SetCaption("SDL GL Application", NULL);

    SDL_SetVideoMode(800, 600, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();

    gluPerspective(70,(double)640/480,1,1000);

    glEnable(GL_DEPTH_TEST);
}
