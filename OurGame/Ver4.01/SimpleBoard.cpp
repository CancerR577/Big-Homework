#include "SimpleBoard.h"
#include <iostream>

SimpleBoard::SimpleBoard(int r, int c,StartAndEnd* sae, int t)
    : Squares::Squares(r,c,sae,t)
    {
        if (t == 1)
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
        if (t == 2)
        {
            int X { 100 };
            int Y { 100 };
            int W { 100 };
            int H { W };
            int w { 80 };
            int h { w };
            int w1 { w };
            int h1 { (H - h) / 2 };
            int w2 { h1 };
            int h2 { (H - 3 * h1) / 2 };
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
                        HeBox[i][j] = new EnterBox(X + w2 + (W - w2) * j, Y + (H - h1) * i + (h1 + h2) * j, w1, h1, s[0][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i == r)
                    {
                        HeBox[i][j] = new EnterBox(X + w2 + (W - w2) * j, Y + (H - h1) * i + (h1 + h2) * j, w1, h1, s[r - 1][j]);
                        HeBox[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        HeBox[i][j] = new EnterBox(X + w2 + (W - w2) * j, Y + (H - h1) * i + (h1 + h2) * j, w1, h1, s[i - 1][j], s[i][j]);
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
                        VeBox1[i][j] = new EnterBox(X + (W - w2) * j, Y + h1 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i][0]);
                        VeBox1[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (j == c)
                    {
                        VeBox1[i][j] = new EnterBox(X + (W - w2) * j, Y + h1 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i][c - 1]);
                        VeBox1[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else
                    {
                        VeBox1[i][j] = new EnterBox(X + (W - w2) * j, Y + h1 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i][j - 1], s[i][j]);
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
                        VeBox2[i][j] = new EnterBox(X + (W - w2) * j, Y - h2 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[0][j - 1]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i == r && j != c)
                    {
                        VeBox2[i][j] = new EnterBox(X + (W - w2) * j, Y - h2 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[r - 1][j]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != 0 && j == 0)
                    {
                        VeBox2[i][j] = new EnterBox(X + (W - w2) * j, Y - h2 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i - 1][0]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != r && j == c)
                    {
                        VeBox2[i][j] = new EnterBox(X + (W - w2) * j, Y - h2 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i][c - 1]);
                        VeBox2[i][j]->box(FL_PLASTIC_DOWN_FRAME);
                    }
                    else if (i != 0 && i != r && j != 0 && j != c)
                    {
                        VeBox2[i][j] = new EnterBox(X + (W - w2) * j, Y - h2 + (H - h1) * i + (h2 + h1) * j, w2, h2, s[i][j - 1], s[i - 1][j]);
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
