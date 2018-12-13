#include "EnterBox.h"

int main(int argc, char **argv)
{
    Fl_Window* w  =  new  Fl_Window(300, 500);
    EnterBox *eBox  =  new  EnterBox(25,50,120,25,"",true);
    eBox->box(FL_UP_BOX);
    w->end();
    w->show(argc, argv);
    return Fl::run();
}
