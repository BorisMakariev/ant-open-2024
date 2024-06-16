#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_timer.h"
#include "Object.h"
#include "Meteoroid.h"
#include "Rocket.h"
#include <vector>
using namespace std;

class Game
{
    public:
        Game();
        ~Game();

        void start_window(int WINDOW_HEIGHT, int WINDOW_WIDTH, int X, int Y);

        void play_game();

        SDL_Window* win;
        SDL_Renderer* rend;

};

#endif // GAME_H
