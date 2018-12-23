#include "Squares.h"
#include "StartAndEnd.h"
#include "DotBox.h"
#include <iostream>

Squares::Squares(int r, int c,StartAndEnd* &sae)
    : row { r }
    , column { c }
    , sqsae {sae}
    {
        scbd = new ScoreBoard ( 0 , 0 , 1 , sqsae);
        int i, j;
        s = new SquareUnit **[r];
        d = new DotBox **[r + 1];
        for(i = 0; i < r; i++)
        {
            s[i] = new SquareUnit *[c];

        }
         for(i = 0; i < r + 1; i++ )
        {
            d[i] = new DotBox *[c + 1];
        }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                s[i][j] = new SquareUnit(50 + 125 * j, 125 + 125 * i, 100, 100, 4, 1, this);
                s[i][j]->box(FL_FLAT_BOX);
                d[i][j] = new DotBox(25 + 125 * j, 100+ 125 * i);
            }
        }
        for (i = 0; i < r + 1; i++)
        {
            for (j = 0; j < c + 1; j++)
            {
                d[i][j] = new DotBox(25 + 125 * j, 100+ 125 * i);
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
