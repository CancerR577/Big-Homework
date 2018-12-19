#include "Squares.h"
#include <iostream>

Squares::Squares(int r, int c )
    : row { r }
    , column { c }
    {
        scbd = new ScoreBoard ( 0 , 0 , 1 );
        int i, j;
        s = new SquareUnit **[r];
        for(i = 0; i < r; i++ )
        {
            s[i] = new SquareUnit *[c];
        }

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                s[i][j] = new SquareUnit(50 + 125 * j, 125 + 125 * i, 100, 100, 4, 1, this);
                s[i][j]->box(FL_UP_BOX);
            }
        }
    }

void Squares::AllChangePlayer()
{
    scbd -> ScoreBoard::change_turn();
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            s[i][j]->changePlayer();
            s[i][j]->redraw();
        }
    }
    std::cout << "Player change!" << std::endl;
}

void Squares::plus_score1()
{
    scbd ->add_score1();
}

void Squares::plus_score2()
{
    scbd ->add_score2();
}
