#include "EnterBox.h"
#include "SquareUnit.h"




int main(int argc, char **argv)
{
    Fl_Window* w  =  new  Fl_Window(600, 500);

    SquareUnit *s[2][2];
    int const Srow = sizeof(s) / sizeof(s[0]);
    int const Scolumn = sizeof(s[0]) / sizeof(s[0][0]);
    for (int i = 0; i < Srow; i++)
    {
        for (int j = 0; j < Scolumn; j++)
        {
            s[i][j] = new SquareUnit(50 + 125 * j,125 + 125 * i,100,100,"",4);
            s[i][j]->box(FL_UP_BOX);
        }
    }

    EnterBox *HeBox[3][2];//Horizontal
    int const Hrow = sizeof(HeBox) / sizeof(HeBox[0]);
    int const Hcolumn = sizeof(HeBox[0]) / sizeof(HeBox[0][0]);
    for (int i = 0; i < Hrow; i++)
    {
        for (int j = 0; j < Hcolumn; j++)
        {
            switch (i)
            {
            case 0:
                HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, "", true, s[0][j]);
                HeBox[i][j]->box(FL_UP_BOX);
                break;
            case Hrow - 1:
                HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, "", true, s[Hrow - 2][j]);
                HeBox[i][j]->box(FL_UP_BOX);
                break;
            default:
                HeBox[i][j] = new EnterBox(50 + 125 * j, 100 + 125 * i, 100, 25, "", true, s[i - 1][j], s[i][j]);
                HeBox[i][j]->box(FL_UP_BOX);
            }
        }
    }
    EnterBox *VeBox[2][3];//Vertical
    int const Vrow = sizeof(VeBox) / sizeof(VeBox[0]);
    int const Vcolumn = sizeof(VeBox[0]) / sizeof(VeBox[0][0]);
    for (int i = 0; i < Vrow; i++)
    {
        for (int j = 0; j < Vcolumn; j++)
        {
            switch (j)
            {
            case 0:
                VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, "", true, s[i][0]);
                VeBox[i][j]->box(FL_UP_BOX);
                break;
            case Vcolumn - 1:
                VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, "", true, s[i][Vcolumn - 2]);
                VeBox[i][j]->box(FL_UP_BOX);
                break;
            default:
                VeBox[i][j] = new EnterBox(25 + 125 * j, 125 + 125 * i, 25, 100, "", true, s[i][j - 1], s[i][j]);
                VeBox[i][j]->box(FL_UP_BOX);
            }
        }
    }

    w->end();
    w->show(argc, argv);
    return Fl::run();
}


