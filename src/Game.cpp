#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_timer.h"
#include "Object.h"
#include "Meteoroid.h"
#include "Player.h"
#include <iostream>

using namespace std;

Game::Game()
{
    //ctor
}

Game::~Game()
{
    //dtor
}

void Game::start_window(const int WINDOW_HEIGHT, const int WINDOW_WIDTH, int X, int Y)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "SDL INIT ERROR: " << SDL_GetError() << endl;
    }
    win = SDL_CreateWindow("GAME", X, Y, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    rend = SDL_CreateRenderer(win, -1, render_flags);
}

void Game::play_game()
{
    Player player1;
    player1.init(250, 586, ".\\sprites\\random.png", rend);

    vector<Meteoroid> meteoroids;
    Meteoroid meteo;

    vector<Rocket> rockets;
    Rocket rocko;

    meteo.init(rand() % 500, 16, rend);
    meteoroids.push_back(meteo);

    meteo.init(rand() % 500, 16, rend);
    meteoroids.push_back(meteo);

    meteo.init(rand() % 500, 16, rend);
    meteoroids.push_back(meteo);

    meteo.init(rand() % 500, 16, rend);
    meteoroids.push_back(meteo);

    SDL_Event event;

    while (1)
    {
        for (int i = 0; i < meteoroids.size(); i++)
        {
            meteoroids[i].fall();
            SDL_RenderCopy(rend, meteoroids[i].m_texture, NULL, &meteoroids[i].m_rect);
            if (player1.place_meeting(player1.m_rect.x, player1.m_rect.y, meteoroids[i]))
            {
                cout << player1.m_score << endl;
                // && meteoroids[i].m_peperoid = true
                exit(0);
            }
            if (meteoroids[i].m_rect.y == 0)
            {
                meteoroids[i].init(rand() % 500, 16, rend);
            }else if (meteoroids[i].m_rect.y + meteoroids[i].m_rect.h + meteoroids[i].m_random_y >= 650)
            {
                player1.m_score++;
            }
        }
        if (SDL_PollEvent(&event) == SDL_PRESSED)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && player1.m_peperoid_counter > 0)
            {
                player1.m_peperoid_counter--;
                rocko.init(player1.m_rect.x, player1.m_rect.y, ".\\sprites\\random0.png", rend);
                rockets.push_back(rocko);
            }
        }
        for (int i = 0; i < rockets.size(); i++)
        {
            rockets[i].shoot_up();
            SDL_RenderCopy(rend, rockets[i].m_texture, NULL, &rockets[i].m_rect);

        }
        player1.movement();
        SDL_RenderCopy(rend, player1.m_texture, NULL, &player1.m_rect);
        SDL_RenderPresent(rend);
        SDL_Delay(1000/50);
        SDL_RenderClear(rend);
    }



    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
