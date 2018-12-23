#include "SimpleBoard.h"

SimpleBoard::SimpleBoard(int r, int c,StartAndEnd* sae)
    : Squares::Squares(r,c,sae)
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
                    HeBox[i][j] = new EnterBox(45 + 125 * j, 100 + 125 * i, 105, 15, s[0][j]);
                    HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                }
                else if (i == r)
                {
                    HeBox[i][j] = new EnterBox(45 + 125 * j, 100 + 125 * i, 105, 15, s[r - 1][j]);
                    HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                }
                else
                {
                    HeBox[i][j] = new EnterBox(45 + 125 * j, 100 + 125 * i, 105, 15, s[i - 1][j], s[i][j]);
                    HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                }
            }
        }


        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c + 1; j++)
            {
                if (j == 0)
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 120 + 125 * i, 15, 105, s[i][0]);
                    VeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                }
                else if (j == c)
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 120 + 125 * i, 15, 105, s[i][c - 1]);
                    VeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                }
                else
                {
                    VeBox[i][j] = new EnterBox(25 + 125 * j, 120 + 125 * i, 15, 105, s[i][j - 1], s[i][j]);
                    VeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
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
