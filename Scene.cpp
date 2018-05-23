#include "Scene.h"

using namespace Cagan;

Scene::Scene()
{
    m_camera = NULL;

    m_Width = 1280;
    m_Height = 720;

    m_FullScreen = false;
    m_VMFlag = 0;
    m_Bpp = 32;

    m_Screen = NULL;
    m_glcontext = NULL;

}

Scene::~Scene()
{
    if(m_glcontext != NULL)
        SDL_GL_DeleteContext(m_glcontext);
    //dtor
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void Scene::addObject(Object* obj)
{
    m_objects.push_back(obj);
    obj->init();
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

    SDL_GL_SwapWindow(m_Window);

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
    // initialisation des composant de SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    // interval : 0 for immediate updates, 1 for updates synchronized with the vertical retrace, -1 for adaptive vsync; see Remarks
    SDL_GL_SetSwapInterval(1);

    if( m_FullScreen )
	{
		m_VMFlag = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN;
	}
	else
	{
		m_VMFlag = SDL_WINDOW_OPENGL;
	}

    m_Window = SDL_CreateWindow("SDL GL Application",
                                    SDL_WINDOWPOS_CENTERED ,
                                    SDL_WINDOWPOS_CENTERED ,
                                    m_Width,
                                    m_Height,
                                    m_VMFlag);

    if (m_Window == NULL) {
        printf("Unable to initialize window : %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    m_glcontext = SDL_GL_CreateContext(m_Window);

    if (m_glcontext == NULL) {
        printf("Unable to initialize openGL : %s", SDL_GetError());
        SDL_Quit();
        return;
    }

	double VideoRatio = (double)m_Width / (double)m_Height;

    glMatrixMode( GL_PROJECTION );

    gluPerspective(70, VideoRatio, 1, 1000);

    atexit(SDL_Quit);

    //
    // active le test de profondeur
    //
    glEnable(GL_DEPTH_TEST);

    //
    // activation des textures
    //
    glEnable(GL_TEXTURE_2D);



    //
    // activation de la lumière
    //
    //glEnable(GL_LIGHTING);




}

void Scene::setCamera(Camera* camera)
{
    m_camera = camera;
}

