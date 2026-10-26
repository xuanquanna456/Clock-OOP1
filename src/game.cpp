#include "game.hpp"

Game::Game()
{
    clock = Clock(GetScreenWidth() / 2.0f - 100, {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f});
}
void Game::update_game_time()
{

    time_t t = time(0);
    tm *now = localtime(&t);
    game_time.hours = now->tm_hour % 12;

    game_time.seconds = now->tm_sec;

    game_time.minutes = now->tm_min;
}
void Game::main_game()
{
    while (!WindowShouldClose())
    {
        update_game_time();
        clock.Update(*this);

        // Drawing
        BeginDrawing();

        ClearBackground(GRAY);

        clock.Draw();

        EndDrawing();
    }
}
