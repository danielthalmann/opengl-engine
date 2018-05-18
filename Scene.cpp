#include "Scene.h"

using namespace Cagan;

Scene::Scene()
{
    m_camera = NULL;
    m_Width = 800;
    m_Height = 600;
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
        if(m_camera == NULL){
           gluLookAt(3,4,2,0,0,0,0,0,1);
        }else {
           float* lookAt = m_camera->getLookAt();
           gluLookAt(lookAt[0],lookAt[1],lookAt[2],lookAt[3],lookAt[4],lookAt[5],lookAt[6],lookAt[7],lookAt[8]);
        }


        (*iter)->draw();
    }

    glFlush();
    SDL_GL_SwapBuffers();

}

void Scene::update(unsigned int ellapsed_time)
{
    if(m_camera != NULL){
        m_camera->update(ellapsed_time);
    }

    for (std::vector<Object*>::iterator iter = m_objects.begin(); iter != m_objects.end(); iter++) {
        (*iter)->update(ellapsed_time);
    }
}

void Scene::init()
{

    SDL_Init(SDL_INIT_VIDEO);

    atexit(SDL_Quit);

    SDL_WM_SetCaption("SDL GL Application", NULL);

    SDL_SetVideoMode(m_Width, m_Height, 32, SDL_OPENGL);

    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();

    gluPerspective(70,(double)m_Width/(double)m_Height, 1, 1000);

    glEnable(GL_DEPTH_TEST);
}

void Scene::setCamera(Camera* camera)
{
    m_camera = camera;
}

