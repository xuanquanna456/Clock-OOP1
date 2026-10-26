#pragma once

#include "clock.hpp"
#include "Time.hpp"
#include <ctime>

class Game{
public:
    Clock clock;
    Time game_time;
    Game();
    void main_game();
    void update_game_time();
    
};
