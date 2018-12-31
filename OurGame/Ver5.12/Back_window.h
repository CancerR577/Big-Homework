#ifndef BACK_WINDOW_H_INCLUDED
#define BACK_WINDOW_H_INCLUDED

#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>
#include <Fl/Fl_Window.H>


class Back_Window : public Fl_Window
{
public:
    Back_Window(int W = 1000, int H = 950, const char* title = "Our game", int choice = 0) : Fl_Window(W,H,title)
    {
        BackBox = new Fl_Box(0,0,W,H);
        fl_register_images();
        switch(choice){
        case 0:
            background = Fl_Shared_Image::get("Background.PNG");
            break;
        case 1:
            background = Fl_Shared_Image::get("First.PNG");
            break;
        }

        BackBox->image(background->copy(W,H));
        redraw();
    }
private:
    Fl_Shared_Image *background;
    Fl_Box *BackBox;
};



#endif // BACK_WINDOW_H_INCLUDED
