#include "Back_window.h"

Back_Window::Back_Window(int W, int H, const char* title)
    : Fl_Window(W,H,title)
    {
        BackBox = new Fl_Box(0,0,W,H);
        fl_register_images();
        background = Fl_Shared_Image::get("Img/Background.PNG");
        BackBox->image(background->copy(W,H));
        redraw();
    }
