#include "SimpleBoard.h"

SimpleBoard::SimpleBoard(int r, int c )
    : Squares::Squares(r, c)
    {
        int i, j;
        EnterBox *HeBox[r + 1][c];//Horizontal EnterBox
        EnterBox *VeBox[r][c + 1];//Vertical EnterBox
        DegTable = new int *[r];
        for(i = 0; i < r; i++ )
        {
            DegTable[i] = new int [c];
        }

        for (i = 0; i < r + 1; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (i == 0)
                {
                    HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, true, s[0][j]);
                    HeBox[i][j]->box(FL_UP_BOX);
                }
                else if (i == r)
                {
                    HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, true, s[r - 1][j]);
                    HeBox[i][j]->box(FL_UP_BOX);
                }
                else
                {
                    HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, true, s[i - 1][j], s[i][j]);
                    HeBox[i][j]->box(FL_UP_BOX);
                }
            }
        }


        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c + 1; j++)
            {
                if (j == 0)
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, true, s[i][0]);
                    VeBox[i][j]->box(FL_UP_BOX);
                }
                else if (j == c)
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, true, s[i][c - 1]);
                    VeBox[i][j]->box(FL_UP_BOX);
                }
                else
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, true, s[i][j - 1], s[i][j]);
                    VeBox[i][j]->box(FL_UP_BOX);
                }
            }
        }

        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++)
            {
                DegTable[i][j] = s[i][j]->getdeg();
            }
        }
    }
