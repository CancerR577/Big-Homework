#include "Squares.h"
#include "StartAndEnd.h"
#include "DotBox.h"
#include <iostream>
#include <algorithm>

using std::min;

Squares::Squares(int r, int c,StartAndEnd* sae, int t)
    : row { r }
    , column { c }
    , sqsae { sae }
    , type { t }
    {
        if (t == 1)
        {
            const int X { 50 };
            const int Y { 100 };
            const int LX { 900 };
            const int LY { 600 };
            const int L { min( LY / (r + 1), LX / (c + 1)) };
            const int D { L / 10 };
            const int x { X  + (LX - c * L - D) / 2 };
            const int y { Y  + (LY - r * L - D) / 2 };

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
                    s[i][j] = new SquareUnit( x + D + L * j, y + D + L * i, L - D , L - D , 4, this);
                }
            }
            for (i = 0; i < r + 1; i++)
            {
                for (j = 0; j < c + 1; j++)
                {
                    d[i][j] = new DotBox( x + L * j, y + L * i , D , D );
                }
            }
        }
        if (t == 2)
        {
            const int X { 50 };
            const int Y { 100 };
            const int LX { 900 };
            const int LY { 600 };
            const int L { min(  LY / (r + (c + 1) / 2), LX / (c + 1)) };
            const int D { L / 10 };
            const int x { X  + (LX - c * L - D) / 2 };
            const int y { Y  + (LY - r * L - (c - 1) * L / 2 - D) / 2 };

            scbd = new ScoreBoard ( 0 , 0 , 1 , sqsae);
            int i, j;
            s = new SquareUnit **[r];
            d = new DotBox **[2 * r + c];
            for(i = 0; i < r; i++)
            {
                s[i] = new SquareUnit *[c];

            }
             for(i = 0; i < 2 * r + c; i++ )
            {
                d[i] = new DotBox *[c + 1];
            }
            for (i = 0; i < r; i++)
            {
                for (j = 0; j < c; j++)
                {
                    s[i][j] = new SquareUnit(x + D + L * j, y + D + L * i + L * j / 2, L - D, L - D, 6, this);
                }
            }
            for (j = 0; j < c + 1; j++)
            {
                if (j == 0)
                {
                    for (i = 0; i < 2 * r + 1; i++)
                    {
                        d[i][j] = new DotBox(x, y + L * i / 2, D, D);
                    }
                }
                else if (j == c)
                {
                    for (i = c - 1; i < 2 * r + c; i++)
                    {
                        d[i][j] = new DotBox(x + L * j, y + L * i / 2, D, D);
                    }
                }
                else
                {
                    for (i = j - 1; i < 2 * r + j + 1; i++)
                    {
                        d[i][j] = new DotBox(x + L * j, y + L * i / 2, D, D);
                    }
                }
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
}

void Squares::plus_score1()
{
    scbd ->add_score1();
}

void Squares::plus_score2()
{
    scbd ->add_score2();
}
