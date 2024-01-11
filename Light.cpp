#include "Light.h"

using namespace Cagan;

Light::Light()
{
    m_Position.y =  2.0; m_Position.x = 0.0; m_Position.z = 2.0;// m_Position.a = 0.0;
    m_Ambient.y =  1.0; m_Ambient.x = 1.0; m_Ambient.z =  1.0; m_Ambient.a = 1.0;
    m_Diffuse.y =  0.0; m_Diffuse.x = 0.0; m_Diffuse.z =  0.0; m_Diffuse.a = 1.0;
    m_Specular.y =  1.0; m_Specular.x = 1.0; m_Specular.z =  1.0; m_Specular.a = 1.0;
    m_theta = 0.0;
}

Light::~Light()
{
    //dtor
}

void Light::draw(){

    glEnable(GL_LIGHT0);

    glRotated(m_theta,0,1,0);


    glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,200);

    glLightfv(GL_LIGHT0, GL_AMBIENT, m_Ambient.getTable());
    glLightfv(GL_LIGHT0,GL_POSITION, m_Position.getTable());
    glLightfv(GL_LIGHT0, GL_DIFFUSE, m_Diffuse.getTable());
    glLightfv(GL_LIGHT0, GL_SPECULAR, m_Specular.getTable());


/*
    glLightfv(GL_LIGHT0, GL_DIFFUSE, m_Diffuse.getTable());

    GLfloat shininess[] = {50};

    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

*/
};

void Light::update(unsigned int ellapsed_time){

    m_theta += (1.0 / 400) * ellapsed_time;

};
