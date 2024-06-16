#include "Rocket.h"

Rocket::Rocket()
{
    //ctor
}

Rocket::~Rocket()
{
    //dtor
}

void Rocket::shoot_up()
{
    m_rect.y -= m_y_speed;
}
