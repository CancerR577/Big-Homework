#include "SimpleBoard.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
int main(int argc, char **argv)
{
    Fl_Window* w  =  new  Fl_Window(1000, 1000);
    Point xy(100, 100);

    SimpleBoard(4, 4);

    w->end();
    w->show(argc, argv);
    return Fl::run();
}

