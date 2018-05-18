#include "Scene.h"

using namespace Cagan;

Scene::Scene()
{
    m_camera = NULL;

    m_Width = 1920;
    m_Height = 1200;

    m_FullScreen = true;
    m_VMFlag = 0;
    m_Bpp = 32;

    m_Screen = NULL;

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
    // initialisation des composant de SDL
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        printf("Unable to initialize SDL: %s", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_GL_SetAttribute( SDL_GL_SWAP_CONTROL, 1 );
    SDL_GL_SetAttribute( SDL_GL_ACCELERATED_VISUAL, 1 );		// Enable hardware acceleration

    if( m_FullScreen )
	{
		m_VMFlag = SDL_OPENGL | SDL_FULLSCREEN;
	}
	else
	{
		m_VMFlag = SDL_OPENGL;
	}

	double VideoRatio = (double)m_Width/(double)m_Height;

	if( SDL_VideoModeOK( m_Width, m_Height, m_Bpp, m_VMFlag ) != 0 )
	{
		if( m_Screen )
			SDL_FreeSurface( m_Screen );

        m_Screen = SDL_SetVideoMode(m_Width, m_Height, 32, m_VMFlag);

        SDL_WM_SetCaption("SDL GL Application", NULL);

        glMatrixMode( GL_PROJECTION );

        gluPerspective(70, VideoRatio, 1, 1000);

        atexit(SDL_Quit);

        //
        // active le test de profondeur
        //
        glEnable(GL_DEPTH_TEST);


	} else {

        printf("Unable to initialize video mode: (%d)x(%d)x(%d) : %s", m_Width, m_Height, m_Bpp, SDL_GetError());
        SDL_Quit();
        return;

	}

}

void Scene::setCamera(Camera* camera)
{
    m_camera = camera;
}

