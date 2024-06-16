#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class Object
{
    public:
        Object();
        ~Object();

        SDL_Rect m_rect;
        SDL_Texture* m_texture;

        void init(int x, int y, string image_path, SDL_Renderer* renderer);
        void destroy();

        bool place_meeting(int x, int y, Object object);

};

#endif // OBJECT_H
