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
            const double Lx { 700 / ( c + 2 ) };
            const double Ly { 700 / ( r + 2 ) };
            const double L { min( Lx , Ly ) };
            const double x0 { ( 700 - c * L ) / 2 };
            const double y0 { ( 700 - r * L ) / 2 + 110 };
            const double W { L / 1.2 } ;
            const double w { W * 0.1 };
            const double pw { W + w };

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
                    s[i][j] = new SquareUnit( x0 + w + W * j, y0 + w + W * i, W , W , 4, this);
                }
            }
            for (i = 0; i < r + 1; i++)
            {
                for (j = 0; j < c + 1; j++)
                {
                    d[i][j] = new DotBox( x0 + pw * j, y0 + pw * i , w , w );
                }
            }
        }
        if (t == 2)
        {
            const double Lx { 700 / ( c + 2 ) };
            const double Ly { 700 / ( r + 2 ) };
            const double L { min( Lx , Ly ) };
            const double X { ( 700 - c * L ) / 2 };
            const double Y { ( 700 - r * L ) / 2 + 110 };
            int W { L / 1.2 };
            int H { W };
            int w { L * 0.7 };
            int h { w };
            int w1 { w };
            int h1 { (H - h) / 2 };
            int w2 { h1 };
            int h2 { (H - 3 * h1) / 2 };
            int x { X + w2};
            int y { Y + h1};

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
                    s[i][j] = new SquareUnit(x + (W - w2) * j, y + (H - h1) * i + (h1 + h2) * j, w, h, 6, this);
                }
            }
            for (j = 0; j < c + 1; j++)
            {
                if (j == 0)
                {
                    for (i = 0; i < 2 * r + 1; i++)
                    {
                        d[i][j] = new DotBox(X, Y + (h1 + h2) * i, w2, h1);
                    }
                }
                else if (j == c)
                {
                    for (i = c - 1; i < 2 * r + c; i++)
                    {
                        d[i][j] = new DotBox(X + (W - w2) * j, Y + (h1 + h2) * i, w2, h1);
                    }
                }
                else
                {
                    for (i = j - 1; i < 2 * r + j + 1; i++)
                    {
                        d[i][j] = new DotBox(X + (W - w2) * j, Y + (h1 + h2) * i, w2, h1);
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
