#pragma once

#ifndef LIBGAME_H_INCLUDED
#define LIBGAME_H_INCLUDED

void gotoxy(int x, int y);
void SetCursor();
void PrintFrame(int width_i, int width_f, int height_i, int height_f);
void Delay(int _x);
void Pause();

#endif

