#include "SkyBox.h"

using namespace Cagan;

SkyBox::SkyBox()
{
    m_width = 10.0;
    m_height = 5.0;
}

SkyBox::~SkyBox()
{
    //dtor
}

void SkyBox::init()
{
    m_Textures[0] = loadTexture("textures\\Front.bmp");
    m_Textures[1] = loadTexture("textures\\Left.bmp");
    m_Textures[2] = loadTexture("textures\\Back.bmp");
    m_Textures[3] = loadTexture("textures\\Right.bmp");
}

void SkyBox::draw()
{

    glPushMatrix();


    for (int i = 0; i < 4; i++)
    {
        glBindTexture(GL_TEXTURE_2D, m_Textures[i]);

        glBegin(GL_QUADS);
            glTexCoord2d(0,1);
            glVertex3d(m_width,m_width,m_height);
            glTexCoord2d(0,0);
            glVertex3d(m_width,m_width,-m_height);
            glTexCoord2d(1,0);
            glVertex3d(-m_width,m_width,-m_height);
            glTexCoord2d(1,1);
            glVertex3d(-m_width,m_width,m_height);
        glEnd();

        glRotated(90,0,0,1);
    }

    glPopMatrix();

}

void SkyBox::update(unsigned int ellapsed_time)
{

}
