#include <iostream>
#include <memory>
#include "game.h"

using namespace std;

int main()
{
    Game * game = new Game(  1920 //Width
                           , 1080 //Height
                           , "Drawer" //title
                           , 40   //X Acceleration for the drawer
                           , 40   //y Acceleration for the drawer
                           );
    game->game_setup();
    game->game_shutdown();
    return 0;
}
