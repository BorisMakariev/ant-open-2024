#include "Meteoroid.h"


Meteoroid::Meteoroid()
{
    //ctor
}

Meteoroid::~Meteoroid()
{
    //dtor
}

void Meteoroid::init(int x, int y, SDL_Renderer* renderer)
{
    SDL_Surface* surface;
    if (rand() % m_peperoid_chance == 0)
    {
        m_peperoid = true;
        surface = IMG_Load(".\\sprites\\random1.png");
    }else
    {
        m_peperoid = false;
        surface = IMG_Load(".\\sprites\\random.png");
    }
    m_texture =  SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_rect.w, &m_rect.h);
    m_rect.x = x;
    m_rect.y = y;
    SDL_FreeSurface(surface);

    if (rand() % 2 == 0)
    {
        m_random_x = rand() % m_max_fall;
    }else
    {
        m_random_x = (rand() % m_max_fall) * -1;
    }

    do
    {
        m_random_y = (rand() % m_max_fall);
    }while (m_random_y == 0);

}

void Meteoroid::destroy()
{
    SDL_DestroyTexture(m_texture);
}

void Meteoroid::fall()
{
    m_rect.x += m_random_x;
    m_rect.y += m_random_y;

    if (m_rect.x <= 0 || m_rect.x + m_rect.w >= 586)
    {
        m_random_x *= -1;
    }
    if (m_rect.y + m_rect.h >= 650 || m_rect.y <= 0)
    {
        m_rect.y = 0;
    }
}
