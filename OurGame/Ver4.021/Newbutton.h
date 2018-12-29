#ifndef NEWBUTTON_H_INCLUDED
#define NEWBUTTON_H_INCLUDED

#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>

class NewButton : public Fl_Button
{
public:
    NewButton(int X, int Y, int W, int H, int choice) : Fl_Button(X,Y,W,H)
    {
        fl_register_images();
        switch(choice){
        case 0:
           m_pSharedImage = Fl_Shared_Image::get("Start.PNG"); break;
        case 1:
           m_pSharedImage = Fl_Shared_Image::get("Quit.PNG");  break;
        case 2:
           m_pSharedImage = Fl_Shared_Image::get("Default.PNG"); break;
        case 3:
           m_pSharedImage = Fl_Shared_Image::get("Customized.PNG"); break;
        case 4:
           m_pSharedImage = Fl_Shared_Image::get("Back.PNG"); break;
        }
        image(m_pSharedImage->copy(w(),h()));
        redraw();
    }
   private:
    Fl_Shared_Image* m_pSharedImage;
};

#endif // NEWBUTTON_H_INCLUDED
