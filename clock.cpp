#include "Clock.h"

using namespace Cagan;

Clock::Clock()
{
    last_time = SDL_GetTicks();
}

Clock::~Clock()
{
    //dtor
}


unsigned int Clock::getEllapsed()
{

    current_time = SDL_GetTicks();

    ellapsed_time = current_time - last_time;

    last_time = current_time;

    return ellapsed_time;

}
