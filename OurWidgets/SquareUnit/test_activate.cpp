#include "EnterBox.h"
#include "SquareUnit.h"




int main(int argc, char **argv)
{
    Fl_Window* w  =  new  Fl_Window(300, 500);

    SquareUnit *s = new SquareUnit(200,100,25,25,"",4);
    s->box(FL_FLAT_BOX);
    SquareUnit *s2 = new SquareUnit(200,200,25,25,"",1);
    s2->box(FL_FLAT_BOX);

    EnterBox *eBox[4];
    for (int i = 0; i < 3; i++)
    {
        eBox[i] = new EnterBox(50, 100 + 50 * i, 100, 25, "", true, s);
        eBox[i]->box(FL_UP_BOX);
    }
    eBox[3] = new EnterBox(50, 250, 100, 25, "", true, s, s2);
    eBox[3]->box(FL_UP_BOX);

    w->end();
    w->show(argc, argv);
    return Fl::run();
}


