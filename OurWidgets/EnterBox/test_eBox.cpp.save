#include <errno.h>
#include <FL/fl_ask.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/fl_draw.H>
#include <iostream>
#include "EnterBox.h"


DotBox* dot_point[6][6];
int main(int argc, char **argv)
{

    Fl_Window *w = new Fl_Window(500,500);
    creat_dot(hard, dot_point);
    EnterBox *eBox1  =  new  EnterBox(25,50,80,10,"",true);
    EnterBox *eBox2  =  new  EnterBox(25,60,10,70,"",true);
    EnterBox *eBox3  =  new  EnterBox(95,60,10,70,"",true);
    EnterBox *eBox4  =  new  EnterBox(25,127,80,10,"",true);
    eBox1->box(FL_BORDER_FRAME);
    eBox2->box(FL_BORDER_FRAME);
    eBox3->box(FL_BORDER_FRAME);
    eBox4->box(FL_BORDER_FRAME);
    w->end();
    w->show(argc, argv);
    return Fl::run();
}
