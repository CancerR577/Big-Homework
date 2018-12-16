#include "Squares.h"

Squares::Squares(int r, int c)
    : row { r }
    , column { c }
    {
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
                s[i][j] = new SquareUnit(50 + 125 * j, 125 + 125 * i, 100, 100, 4, 1);
                s[i][j]->box(FL_UP_BOX);
            }
        }
    }

void Squares::AllChangePlayer()
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            s[i][j]->changePlayer();
        }
    }
}
