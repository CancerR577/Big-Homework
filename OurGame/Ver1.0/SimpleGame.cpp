#include "OurWidgets/SimpleBoard.h"

int main(int argc, char **argv)
{
    Fl_Window* w  =  new  Fl_Window(1200, 1000);
    Point xy(100, 100);

    SimpleBoard(4, 4);

    w->end();
    w->show(argc, argv);
    return Fl::run();
}

