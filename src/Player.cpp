#include "Player.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Meteoroid.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::init(int x, int y, string image_path, SDL_Renderer* renderer)
{
    SDL_Surface* surface;
    surface = IMG_Load(image_path.c_str());
    m_texture =  SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.w, &m_rect.h);
    m_rect.x = x;
    m_rect.y = y;
    SDL_FreeSurface(surface);
}

void Player::destroy()
{
    SDL_DestroyTexture(m_texture);
}

void Player::movement()
{
    SDL_Event event;

    if (SDL_PollEvent(&event) == SDL_PRESSED)
    {
        switch (event.key.keysym.scancode)
        {
        case SDL_SCANCODE_A:
        case SDL_SCANCODE_LEFT:
            m_rect.x -= m_movement_speed;
            break;
        case SDL_SCANCODE_D:
        case SDL_SCANCODE_RIGHT:
            m_rect.x += m_movement_speed;
        }
    }
}

bool Player::place_meeting(int x, int y, Meteoroid object)
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

