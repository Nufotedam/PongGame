#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "LibGame.h"
#include "Menu.h"

void Menu::MainMenu(int& a)
{
    //  Print the main menu
    char menu[18][71] =
    {
    "                                                                      ",
    "     ooooooooo                                                        ",
    "   ooooooooooooo                             1.- HUMAN VS HUMAN       ",
    "   oo       oooo                             2.- HUMAN VS CPU         ",
    "   oo       oooo                             3.- EXIT                 ",
    "   oo       oooo                                                      ",
    "   oooooooooooo                                                       ",
    "   oooooooooo                                                         ",
    "   oooo                                                               ",
    "   oooo    ooooo    oooo   ooo   oooooo                               ",
    "   oooo  oo    ooo  ooooo  ooo  oo    oo                              ",
    "   oooo  oo    ooo  ooo oo ooo  oo                                    ",
    "   oooo  oo    ooo  ooo  ooooo  oo  oooo                              ",
    "   oooo  oo    ooo  ooo   oooo  oo    ooo                             ",
    "   oooo  oo    ooo  ooo    ooo  ooooooooo                             ",
    "   oooo   oooooo    ooo    ooo   ooooooo                              ",

    };

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            gotoxy(j+5, i+5);
            printf("%c", menu[i][j]);
        }
    }

    //  Get the user Input
    UserInput(a);

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            gotoxy(j + 5, i + 5);
            printf(" ");
        }
    }
}

void Menu::UserInput(int& a)
{
    //  Compare whether the user input was any of the following options
    while (1) {
        a = _getch();
        if (a == '1' || a == '2' || a == '3') {
            break;
        }
    }
}

void Menu::Score(int& _score_p1, int& _score_p2, int width_i, int width_f) {
    //  Print the score of the players in top of the frame
    gotoxy(width_i + 5, 2);
    printf("Score: %d", _score_p1);
    gotoxy(width_f - 15, 2);
    printf("Score: %d", _score_p2);
}

void Menu::GameOver(int width_i, int width_f, int height_i, int height_f, int _player, int& a) {
    //  Print Game over menu
    system("CLS");
    PrintFrame(width_i, width_f, height_i, height_f);

    gotoxy(width_i + width_f / 2, height_i + height_f / 2);
    printf("GAME OVER");
    gotoxy(width_i + width_f / 2, (height_i + height_f / 2) + 2);
    printf("Player %d Wins", _player);
    
    gotoxy(width_i + width_f / 2, (height_i + height_f / 2) + 6);
    printf("Play Again");
    gotoxy(width_i + width_f / 2, (height_i + height_f / 2) + 7);
    printf("1.- HUMAN VS HUMAN");
    gotoxy(width_i + width_f / 2, (height_i + height_f / 2) + 8);
    printf("2.- HUMAN VS CPU");
    gotoxy(width_i + width_f / 2, (height_i + height_f / 2) + 9);
    printf("3.- Exit");

    //  Get the user Input
    UserInput(a);

    system("CLS");
    PrintFrame(width_i, width_f, height_i, height_f);
}