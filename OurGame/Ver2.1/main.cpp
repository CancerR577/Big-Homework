#include "SimpleBoard.h"
#include "Back_window.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Enumerations.H>
int main(int argc, char **argv)
{
    Back_Window *w = new Back_Window(1000,1000);
    Point xy(100, 100);

    SimpleBoard(4, 4);

    w->end();
    w->show(argc, argv);
    return Fl::run();
}

