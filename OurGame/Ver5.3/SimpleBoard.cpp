#include "SimpleBoard.h"
#include <iostream>
#include <algorithm>

using std::min;

SimpleBoard::SimpleBoard(int r, int c,StartAndEnd* sae, int t)
    : Squares::Squares(r,c,sae,t)
    {
        if (t == 1)
        {
            const int X { 200 };
            const int Y { 90 };
            const int LX { 600 };
            const int LY { 600 };
            const int L { min( LY / (r + 1), LX / (c + 1)) };
            const int D { L / 10 };
            const int x { X  + (LX - c * L - D) / 2 };
            const int y { Y  + (LY - r * L - D) / 2 };

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
                        HeBox[i][j] = new EnterBox( x + D + L * j, y + L * i, L - D , D , s[0][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i == r)
                    {
                        HeBox[i][j] = new EnterBox( x + D + L * j, y + L * i, L - D , D , s[r - 1][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        HeBox[i][j] = new EnterBox( x + D + L * j, y + L * i, L - D , D , s[i - 1][j], s[i][j]);
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
                        VeBox[i][j] = new EnterBox( x + L * j, y + D + L * i, D , L - D , s[i][0]);
                        VeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (j == c)
                    {
                        VeBox[i][j] = new EnterBox( x + L * j, y + D + L * i, D , L - D , s[i][c - 1]);
                        VeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        VeBox[i][j] = new EnterBox( x + L * j, y + D + L * i, D , L - D , s[i][j - 1], s[i][j]);
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
        if (t == 2)
        {
            const int X { 200 };
            const int Y { 90 };
            const int LX { 600 };
            const int LY { 600 };
            const int L { min(  LY / (r + (c + 1) / 2), LX / (c + 1)) };
            const int D { L / 10 };
            const int x { X  + (LX - c * L - D) / 2 };
            const int y { Y  + (LY - r * L - (c - 1) * L / 2 - D) / 2 };
            int i, j;
            EnterBox *HeBox[r + 1][c];//Horizontal EnterBox
            EnterBox *VeBox1[r][c + 1];//Vertical EnterBox
            EnterBox *VeBox2[r + 1][c + 1];//Vertical EnterBox
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
                        HeBox[i][j] = new EnterBox(x + D + L * j, y + L * i + L * j / 2, L - D, D, s[0][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i == r)
                    {
                        HeBox[i][j] = new EnterBox(x + D + L * j, y + L * i + L * j / 2, L - D, D, s[r - 1][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        HeBox[i][j] = new EnterBox(x + D + L * j, y + L * i + L * j / 2, L - D, D, s[i - 1][j], s[i][j]);
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
                        VeBox1[i][j] = new EnterBox(x + L * j, y + D + L * i + L * j / 2, D, L / 2 - D, s[i][0]);
                        VeBox1[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (j == c)
                    {
                        VeBox1[i][j] = new EnterBox(x + L * j, y + D + L * i + L * j / 2, D, L / 2 - D, s[i][c - 1]);
                        VeBox1[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        VeBox1[i][j] = new EnterBox(x + L * j, y + D + L * i + L * j / 2, D, L / 2 - D, s[i][j - 1], s[i][j]);
                        VeBox1[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                }
            }

            for (i = 0; i < r + 1; i++)
            {
                for (j = 0; j < c + 1; j++)
                {
                    if (i == 0 && j != 0)
                    {
                        VeBox2[i][j] = new EnterBox(x + L * j, y - L / 2 + D + L * i + L * j / 2, D, L / 2 - D, s[0][j - 1]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i == r && j != c)
                    {
                        VeBox2[i][j] = new EnterBox(x + L * j, y - L / 2 + D + L * i + L * j / 2, D, L / 2 - D, s[r - 1][j]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != 0 && j == 0)
                    {
                        VeBox2[i][j] = new EnterBox(x + L * j, y - L / 2 + D + L * i + L * j / 2, D, L / 2 - D, s[i - 1][0]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != r && j == c)
                    {
                        VeBox2[i][j] = new EnterBox(x + L * j, y - L / 2 + D + L * i + L * j / 2, D, L / 2 - D, s[i][c - 1]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != 0 && i != r && j != 0 && j != c)
                    {
                        VeBox2[i][j] = new EnterBox(x + L * j, y - L / 2 + D + L * i + L * j / 2, D, L / 2 - D, s[i][j - 1], s[i - 1][j]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
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
    }
