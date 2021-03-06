#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class EnterBox : public Fl_Box
{
public:
    int handle(int e)
    {
        if (!enable) return 0;//如果这个某个Box被点过了，就不能再响应
        switch (e)
        {
            case  FL_ENTER://鼠标移上来
                 color(FL_GREEN);
                 redraw();
                 return 1;
            case  FL_LEAVE://鼠标移开
                 color(FL_GRAY);
                 redraw();
                 return 1;
            case FL_PUSH:
                switch (Fl::event_button())
                {
                case FL_LEFT_MOUSE:
                    color(FL_RED);
                    enable = false;//让这个Box不能再响应
                    redraw();
                    return 1;
            }
            break;
        }
    }

    EnterBox(int x, int y, int w, int h, const char *l, bool ee ) : Fl_Box(x,y,w,h,l), enable{ee} {}

private:
    bool enable;
};
