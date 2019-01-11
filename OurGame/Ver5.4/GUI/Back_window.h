#ifndef BACK_WINDOW_H_INCLUDED
#define BACK_WINDOW_H_INCLUDED

#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Fl_Window.H>


class Back_Window : public Fl_Window
{
public:
    Back_Window(int W = 1000, int H = 950, const char* title = "Our game");
private:
    Fl_Shared_Image *background;
    Fl_Box *BackBox;
};



#endif // BACK_WINDOW_H_INCLUDED
