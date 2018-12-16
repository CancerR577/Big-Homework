#ifndef _SQUAREUNIT_H_
#define _SQUAREUNIT_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#include "Point.h"

class Squares;

class SquareUnit : public Fl_Box
{
public:
    SquareUnit(int x, int y, int w, int h, int d, int who);
    int getdeg();
    void setdeg(int d);
    void changePlayer();
    void activation();
    void callSquares();

private:
    int deg;
    int PlayerNumber;
};


#endif // SQUAREUNIT


