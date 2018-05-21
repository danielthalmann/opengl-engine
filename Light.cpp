#include "Light.h"

using namespace Cagan;

Light::Light()
{
    //ctor
}

Light::~Light()
{
    //dtor
}

void Light::draw(){

    glLightfv(GL_LIGHT0,GL_POSITION, m_Position.getTable());

};
