#pragma once
#include<raylib.h>

class Game;

class Clock{
    private:
        int size;
        Vector2 position;
    public:
        float minutes_degrees = 0.0f , seconds_degrees = 0.0f , hours_degrees = 0.0f;
        Clock(): size(0) , position{0 , 0} {}
        Clock(int size , Vector2 position){
            this->size = size;
            this->position = position;
        }
        void Update(Game &game);
        void Draw() const;
        void DrawFace() const;
        void DrawHourMarks() const;
        void DrawMinutesMarks() const;
        void DrawMinutesHand() const;
        void DrawSecondsHand() const;
        void DrawHourHands() const;
        void DrawHourNumbers() const;
    };