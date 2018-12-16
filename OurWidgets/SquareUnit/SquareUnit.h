#ifndef SQUAREUNIT.H
#define SQUAREUNIT.H


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>



class SquareUnit : public Fl_Box
{
public:
    SquareUnit(int x, int y, int w, int h, const char *l, int d) : Fl_Box(x,y,w,h,l), deg{d} {}
    int getdeg() { return deg; }
    void setdeg(int d) { deg = d; }
    inline void activation();
    inline void cb_activate_i();

private:
    int deg;
};

void SquareUnit::activation() {
    switch (deg)
    {
    case 0:
        color(FL_RED);
        redraw();
        break;
    default:
        break;
    }
}

#endif // SQUAREUNIT


