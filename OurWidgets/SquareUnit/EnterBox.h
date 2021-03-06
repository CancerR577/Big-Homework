#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include "SquareUnit.h"


class EnterBox : public Fl_Box
{
public:
    int handle(int e);
    int getisable() { return isable; }
    static void cb_activate(Fl_Widget*, void*);

    EnterBox(int x, int y, int w, int h, const char *l, bool ab, SquareUnit *s)
        : Fl_Box(x,y,w,h,l)
        , isable{ab}
        , square{s}
        {
        }

    EnterBox(int x, int y, int w, int h, const char *l, bool ab, SquareUnit *s, SquareUnit *s2)
        : Fl_Box(x,y,w,h,l)
        , isable{ab}
        , square{s}
        , square2{s2}
        {
        }
private:
    bool isable;
    SquareUnit *square;//用于激活相应的SquareUnit
    SquareUnit *square2;//大部分边对应两个方块
};
