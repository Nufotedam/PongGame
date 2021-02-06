//  William Alejandro Martinez Mora
//  Universidad Jorge Tadeo Lozano
//  PONG GAME - C++ :D

#include <conio.h>
#include <stdlib.h>
#include "LibGame.h"
#include "Paddle.h"
#include "Puck.h"
#include "Menu.h"

int main()
{
    const int MaxScore = 5;     //  Maximum score to win

    int width_i = 3;            //  Frame initial width
    int width_f = 80;           //  Frame final width
    int height_i = 2;           //  Frame initia height
    int height_f = 23;          //  Frame final height
    int middle_width = width_i + width_f / 2;       //  Half the frame width
    int middle_height = height_i + height_f / 2;    //  Half the frame height
    int TimeMovement = 0;       //  How fast the ball movement is updated
    int Option;                 //  User input
    int ScoreP1 = 0;            //  Score pf the Player 1
    int ScoreP2 = 0;            //  Score pf the Player 2
    char Input;                 //  Movement Input

    SetCursor();
    PrintFrame(width_i, width_f, height_i, height_f);

    //  Class declaration
    Menu Menu;
    //  Print the menu
    Menu.MainMenu(Option);
    //  Print the players
    Paddle Player1(width_i, middle_height);
    Player1.Print();
    Paddle Player2(width_f - 1, middle_height);
    Player2.Print();
    Puck ball(middle_width, middle_height, 1, 1);

    //  Print the initial score
    Menu.Score(ScoreP1, ScoreP2, width_i, width_f);

    while (Option != '3') {

        if (_kbhit()) {      
            //  Get the Input
            Input = _getch();
            //  Move the first player up
            if (Input == 'w' && Player1.GetY() > height_i + 3) {
                Player1.Clean();
                Player1.UpdateY(-1);
            }
            //  Move the first player down
            else if (Input == 's' && Player1.GetY() < height_f - 2) {
                Player1.Clean();
                Player1.UpdateY(1);
            }

            if (Option == '1') {
                //  Move the second player up
                if (Input == 'i' && Player2.GetY() > height_i + 3) {
                    Player2.Clean();
                    Player2.UpdateY(-1);
                }
                //  Move the second player down
                else if (Input == 'k' && Player2.GetY() < height_f - 2) {
                    Player2.Clean();
                    Player2.UpdateY(1);
                }
            }
        }
        //  Update the paddles
        Player1.Print();
        Player2.Print();

        if(TimeMovement == 0){
            //  Move the player 2 by the cpu
            if (Option == '2') {
                Player2.IAMovement(ball.GetX(), ball.GetY(), ball.GetDx(), height_i, height_f, 60);
            }
        }

        if (!TimeMovement++) {
            //  Check the players score
            if (ScoreP1 >= MaxScore) {
                Menu.GameOver(width_i, width_f, height_i, height_f, 1, Option);
                //  Reset the game
                ScoreP1 = 0;
                ScoreP2 = 0;
                Player1.SetX(width_i);
                Player2.SetX(width_f - 1);
                Player1.SetY(middle_height);
                Player2.SetY(middle_height);
                Menu.Score(ScoreP1, ScoreP2, width_i, width_f);
            }
            else if (ScoreP2 >= MaxScore) {
                Menu.GameOver(width_i, width_f, height_i, height_f, 2, Option);
                ScoreP1 = 0;
                ScoreP2 = 0;
                //  Reset the game
                Player1.SetX(width_i);
                Player2.SetX(width_f - 1);
                Player1.SetY(middle_height);
                Player2.SetY(middle_height);
                Menu.Score(ScoreP1, ScoreP2, width_i, width_f);
            }
            else {
                //  Move the ball
                ball.BallMovement(width_i, width_f, height_i, height_f, Player1, Player2, ScoreP1, ScoreP2);
            }
        }
        if (TimeMovement > 5) {
            TimeMovement = 0;
        }

        //  Wait
        Delay(10);
    }

    system("CLS");
    return 0;
}
