#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_timer.h"
#include "Object.h"
#include "Meteoroid.h"
#include "Game.h"

using namespace std;

const int WINDOW_WIDTH = 586;
const int WINDOW_HEIGHT = 640;

int main(int argc, char** argv)
{
    while (1)
    {
        Game game;
        game.start_window(WINDOW_HEIGHT, WINDOW_WIDTH, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        game.play_game();
    }
    return 0;
}
