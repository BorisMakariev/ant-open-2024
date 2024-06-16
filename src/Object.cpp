#include "Object.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
using namespace std;

Object::Object()
{
    //ctor
}

Object::~Object()
{
    //dtor
}

void Object::init(int x, int y, string image_path, SDL_Renderer* renderer)
{
    SDL_Surface* surface;
    surface = IMG_Load(image_path.c_str());
    m_texture =  SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.w, &m_rect.h);
    m_rect.x = x;
    m_rect.y = y;
    SDL_FreeSurface(surface);
}

void Object::destroy()
{
    SDL_DestroyTexture(m_texture);
}

bool Object::place_meeting(int x, int y, Object object)
{
    int w = m_rect.w;
    int h = m_rect.h;

    int o_x = object.m_rect.x;
    int o_y = object.m_rect.y;

    int o_w = object.m_rect.w;
    int o_h = object.m_rect.h;

    if (((x >= o_x && x <= (o_x + o_w)) &&
         (y >= o_y && y <= (o_y + o_h))) ||

       (((x + w) >= o_x && (x + w) <= (o_x + o_w)) &&
       (((y + h) >= o_y) && (y + h) <= (o_y + o_h))) ||

        ((x >= o_x && x <= (o_x + o_w)) &&
        ((y + h) >= o_y && (y + h) <= (o_y + o_h))) ||

       (((x + w) >= o_x && (x + w) <= (o_x + o_w)) &&
         (y >= o_y && y <= (o_y + o_h))))
    {
        return true;
    }
    return false;
}
