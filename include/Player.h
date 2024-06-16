#ifndef PLAYER_H
#define PLAYER_H

#include "Meteoroid.h"
#include <Object.h>


class Player : public Object
{
    public:
        Player();
        ~Player();

        SDL_Rect m_rect;
        SDL_Texture* m_texture;

        int m_score = 0;
        int m_peperoid_counter = 4;
        int m_movement_speed = 5;
        bool m_alive = false;

        void init(int x, int y, string image_path, SDL_Renderer* renderer);
        void destroy();

        void movement();
        bool place_meeting(int x, int y, Meteoroid object);

};

#endif // PLAYER_H
