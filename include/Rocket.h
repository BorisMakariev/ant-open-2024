#ifndef ROCKET_H
#define ROCKET_H

#include <Object.h>


class Rocket : public Object
{
    public:
        Rocket();
        ~Rocket();

        int m_y_speed = 5;

        void shoot_up();

};

#endif // ROCKET_H
