#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "LibGame.h"

void gotoxy(int x, int y) {
    //  Go to an specific x and y position in the console screen
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void SetCursor() {
    CONSOLE_CURSOR_INFO cci = { 100, FALSE };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void PrintFrame(int width_i, int width_f, int height_i, int height_f) {
    //  Vertical Lines in the console screen
    for (int j = 4; j <= height_f; j++) {
        gotoxy(height_i, j); printf("%c", 186);
        gotoxy(width_f, j); printf("%c", 186);
    }
    //  Horizontal Lines in the console screen
    for (int i = 2; i <= width_f; i++) {
        gotoxy(i, width_i); printf("%c", 205);
        gotoxy(i, height_f); printf("%c", 205);
    }
}

void Delay(int _x) {
    //  Wait for the next execution
    Sleep(_x);
}

void Pause() {
    //  Pause the execution
    _getch();
}
