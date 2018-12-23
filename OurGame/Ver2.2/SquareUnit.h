#ifndef _SQUAREUNIT_H_
#define _SQUAREUNIT_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Shared_Image.H>
#include "Point.h"

class Squares;

class SquareUnit : public Fl_Box
{
public:
    SquareUnit(int x, int y, int w, int h, int d, int who, Squares* sqss);
    int getdeg();
    void setdeg(int d);
    void changePlayer();
    void activation();
    void activation2();
    void callSquares();

private:
    int deg;
    int PlayerNumber;
    Squares* sqs;
    Fl_Shared_Image *square_pic;
};


#endif // SQUAREUNIT


