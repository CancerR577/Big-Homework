#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

class EnterBox : public Fl_Box
{
public:
    int handle(int e)
    {
        if (!enable) return 0;
        switch (e)
        {
            case  FL_ENTER:
                 color(FL_GREEN);
                 labelsize(14);
                 redraw();
                 return 1;
            case  FL_LEAVE:
                 color(FL_GRAY);
                 labelsize(14);
                 redraw();
                 return 1;
            case FL_PUSH:
                switch (Fl::event_button())
                {
                case FL_LEFT_MOUSE:
                    color(FL_RED);
                    labelsize(14);
                    enable = false;
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
