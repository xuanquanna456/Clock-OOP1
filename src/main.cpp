#include<raylib.h>
#include<iostream>
#include "clock.hpp"
#include "game.hpp"

using namespace std;

int main(){
    InitWindow(800 , 800 , "Clock");
    SetTargetFPS(15);

    Game game;
    game.main_game();
    
    CloseWindow();
    return 0;
}

