#include <stdio.h>
#include "LibGame.h"
#include "Puck.h"
#include "Menu.h"

Puck::Puck(int _x, int _y, int _dx, int _dy) {
    x = _x;
    y = _y;
    dx = _dx;
    dy = _dy;
}

void Puck::Print() const {
    //  Print the ball in the screen
    gotoxy(x, y); printf("%c", 184);
}

void Puck::Clean() const {
    //  Clean the ball
    gotoxy(x, y); printf(" ");
}

void Puck::BallMovement(int width_i, int width_f, int height_i, int height_f, Paddle _player1, Paddle _player2, int& _scoreP1, int& _scoreP2) {
    Menu Menu;
    //  Move the ball with the dx and dy velocity in the screen
    Clean();
    x += dx;
    y += dy;
    Print();
    
    //  Limits in X-axis
    if (x + dx == width_i - 1) {
        Clean();
        //  Bounce
        dx = -dx;
        //  Add points to the player 2
        _scoreP2++;
        Menu.Score(_scoreP1, _scoreP2, width_i, width_f);
        //  Reset the ball in the middle of the frame
        Reset(width_i + width_f / 2, height_i + height_f / 2);
    }
    else if (x + dx == width_f) {
        Clean();
        //  Bounce
        dx = -dx;
        //  Add points to the player 1
        _scoreP1++;
        Menu.Score(_scoreP1, _scoreP2, width_i, width_f);
        //  Reset the ball in the middle of the frame
        Reset(width_i + width_f / 2, height_i + height_f / 2);
    }

    //  Limits in Y-axis
    if (y + dy == height_i + 1 || y + dy == height_f) {
        //  Bounce
        dy = -dy;
    }

    //  Get the player position and bounce if the paddle touch the ball
    if (x + dx == _player1.GetX() && y > _player1.GetY() - 2 && y <= _player1.GetY() + 2) {
        dx = -dx;
    }
    if (x + dx == _player2.GetX() && y > _player2.GetY() - 2 && y <= _player2.GetY() + 2) {
        dx = -dx;
    }
}

void Puck::Reset(int _resetx, int _resety) {
    x = _resetx;
    y = _resety;
}