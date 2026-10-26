#include "clock.hpp"
#include <math.h>
#include <iostream>
#include <raymath.h>
#include "game.hpp"

using namespace std;

void Clock::Update(Game &game)
{
    minutes_degrees = game.game_time.minutes * 6.0f;

    seconds_degrees = game.game_time.seconds;

    hours_degrees = game.game_time.hours * 30.0f;
}

void Clock::Draw() const
{
    DrawFace();
    DrawHourMarks();
    DrawMinutesMarks();
    DrawMinutesHand();
    DrawSecondsHand();
    DrawHourNumbers();
    DrawHourHands();
}

void Clock::DrawFace() const
{
    DrawCircleV(position, size, BLACK);
    DrawCircleV(position, size - 10, WHITE);
}

void Clock::DrawHourMarks() const
{
    int hour_mark_distance_degree = 30;
    float rect_width = 10;
    float rect_height = size - 10;
    Rectangle rect = {position.x, position.y, rect_width, rect_height};
    for (int i = 0; i < 12; i++)
    {
        int degree = i * hour_mark_distance_degree;
        DrawRectanglePro(rect, {rect.width / 2, rect_height}, degree, DARKPURPLE);
    }
    DrawCircle(position.x, position.y, size - 30, RAYWHITE);
}

void Clock::DrawMinutesMarks() const
{
    int minutes_mark_distance_degree = 6;
    float rect_width = 6;
    float rect_height = size - 10;
    Rectangle rect = {position.x, position.y, rect_width, rect_height};
    for (int i = 0; i < 60; i++)
    {
        int degree = i * minutes_mark_distance_degree;
        if (degree % 30 == 0)
            continue;
        DrawRectanglePro(rect, {rect.width / 2, rect_height}, degree, DARKGRAY);
    }
    DrawCircle(position.x, position.y, size - 30, RAYWHITE);
}
void Clock::DrawHourHands() const
{
    float hours_hand_width = 7;
    float hours_hand_height = size * 0.6;
    Rectangle rect = {position.x, position.y, hours_hand_width, hours_hand_height};

    DrawRectanglePro(rect, {hours_hand_width / 2, hours_hand_height}, hours_degrees, BLUE);
}

void Clock::DrawMinutesHand() const
{
    float minutes_hand_width = 8;
    float minutes_hand_height = size * 0.7;

    Rectangle rect = {position.x, position.y, minutes_hand_width, minutes_hand_height};

    DrawRectanglePro(rect, {minutes_hand_width / 2, minutes_hand_height}, minutes_degrees, BLACK);
}

void Clock::DrawSecondsHand() const
{
    float seconds_hand_width = 4;
    float seconds_hand_height = 0.85 * size;

    Rectangle rect = {position.x, position.y, seconds_hand_width, seconds_hand_height};

    DrawRectanglePro(rect, {seconds_hand_width / 2, seconds_hand_height}, seconds_degrees, RED);
}

void Clock::DrawHourNumbers() const
{
    for (int i = 0; i < 12; i++)
    {
        float radians = i * (PI / 6);
        float text_x = (position.x + 0.8 * (size)*sinf(radians));
        float text_y = (position.y - 0.8 * (size)*cosf(radians));

        int number = (i == 0) ? 12 : i;
        int text_height = 30;
        int text_width = MeasureText(TextFormat("%d", number), text_height);

        DrawText(TextFormat("%d", number), text_x - text_width / 2, text_y - text_height / 2, text_height, BLACK);
    }
}