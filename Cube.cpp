#include "Cube.h"

using namespace Cagan;

Cube::Cube()
{
    m_angleZ = 0;
    m_angleX = 0;

}

Cube::~Cube()
{
    //dtor
}

void Cube::init()
{
    m_Texture = loadTexture("textures/ground.jpg");
}

void Cube::draw()
{

    glBindTexture(GL_TEXTURE_2D, m_Texture);
    glPushMatrix();
    glPushAttrib(GL_CURRENT_BIT);

    glRotated(m_angleZ,0,0,1);
    glRotated(m_angleX,1,0,0);

    glBindTexture(GL_TEXTURE_2D, m_Texture);
/*
    for (int i = 0; i < 4; i++)
    {
        glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(1,1,1);
        glTexCoord2d(0,0);
        glVertex3d(1,1,-1);
        glTexCoord2d(1,0);
        glVertex3d(-1,1,-1);
        glTexCoord2d(1,1);
        glVertex3d(-1,1,1);
        glEnd();
        glRotated(90,0,0,1);
    }
*/

    glBegin(GL_QUADS);

    glColor3ub(255,0,0); //face rouge
    glTexCoord2d(0,1); glVertex3d(1,1,1);
    glTexCoord2d(0,0); glVertex3d(1,1,-1);
    glTexCoord2d(1,0); glVertex3d(-1,1,-1);
    glTexCoord2d(1,1); glVertex3d(-1,1,1);


    glColor3ub(0,255,0); //face verte
    glTexCoord2d(0,1); glVertex3d(1,-1,1);
    glTexCoord2d(0,0); glVertex3d(1,-1,-1);
    glTexCoord2d(1,0); glVertex3d(1,1,-1);
    glTexCoord2d(1,1); glVertex3d(1,1,1);


    glColor3ub(0,0,255); //face bleue
    glTexCoord2d(0,1); glVertex3d(-1,-1,1);
    glTexCoord2d(0,0); glVertex3d(-1,-1,-1);
    glTexCoord2d(1,0); glVertex3d(1,-1,-1);
    glTexCoord2d(1,1); glVertex3d(1,-1,1);

    glColor3ub(255,255,0); //face jaune
    glTexCoord2d(0,1); glVertex3d(-1,1,1);
    glTexCoord2d(0,0); glVertex3d(-1,1,-1);
    glTexCoord2d(1,0); glVertex3d(-1,-1,-1);
    glTexCoord2d(1,1); glVertex3d(-1,-1,1);


    glColor3ub(0,255,255); //face cyan
    glTexCoord2d(0,1); glVertex3d(1,1,-1);
    glTexCoord2d(0,0); glVertex3d(1,-1,-1);
    glTexCoord2d(1,0); glVertex3d(-1,-1,-1);
    glTexCoord2d(1,1); glVertex3d(-1,1,-1);


    glColor3ub(255,0,255); //face magenta
    glTexCoord2d(0,1); glVertex3d(1,-1,1);
    glTexCoord2d(0,0); glVertex3d(1,1,1);
    glTexCoord2d(1,0); glVertex3d(-1,1,1);
    glTexCoord2d(1,1); glVertex3d(-1,-1,1);

    glEnd();

    glPopAttrib();
    glPopMatrix();

}

void Cube::update(unsigned int ellapsed_time)
{
    m_angleZ += 0.05 * ellapsed_time;
    m_angleX += 0.05 * ellapsed_time;
}
