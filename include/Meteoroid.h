#ifndef METEOROID_H
#define METEOROID_H

#include <Object.h>
#include <windows.h>

#include <iostream>
#include <vector>

using namespace std;

class Meteoroid : public Object
{
    public:
        Meteoroid();
        ~Meteoroid();

        SDL_Rect m_rect;
        SDL_Texture* m_texture;

        int m_random_x;
        int m_random_y;

        int m_max_fall = 6;

        bool m_peperoid;
        int m_peperoid_chance = 7;

        void init(int x, int y, SDL_Renderer* renderer);
        void destroy();

        void fall();

};

#endif // METEOROID_H
