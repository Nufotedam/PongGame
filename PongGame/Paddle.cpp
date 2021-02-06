#include <stdio.h>
#include "Paddle.h"
#include "LibGame.h"

Paddle::Paddle(int _x, int _y) {
    x = _x;
    y = _y;
}

void Paddle::Print() const {
    //  Print 3 position of the player paddle in the screen
    gotoxy(x, y - 1); printf("%c", 219);
    gotoxy(x, y); printf("%c", 219);
    gotoxy(x, y + 1); printf("%c", 219);
}

void Paddle::Clean() const {
    //  Clean the current paddle printed
    gotoxy(x, y - 1); printf(" ");
    gotoxy(x, y); printf(" ");
    gotoxy(x, y + 1); printf(" ");
}

void Paddle::UpdateY(int _movement) {
    //  move the paddle in Y-axis
    y += _movement;
}

void Paddle::IAMovement(int _ballx, int _bally, int _balldx, int height_i, int height_f, int limit_reaction) {
    //  Move the player 2 paddle, base on the ball position
    if (_ballx > limit_reaction && _balldx > 0) {
        Clean();
        if (_bally > y && y < height_f - 2) {
            //  move the paddle up
            y++;
        }
        if (_bally < y && y > height_i + 3) {
            //  move the paddle down
            y--;
        }
        Print();
    }
}