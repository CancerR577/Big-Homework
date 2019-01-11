#include "Newbutton.h"

NewButton::NewButton(int X, int Y, int W, int H, int choice)
    : Fl_Button(X,Y,W,H)
    {
        fl_register_images();
        switch(choice){
        case 0:
           m_pSharedImage = Fl_Shared_Image::get("Img/Start.PNG"); break;
        case 1:
           m_pSharedImage = Fl_Shared_Image::get("Img/Quit.PNG");  break;
        case 2:
           m_pSharedImage = Fl_Shared_Image::get("Img/Default.PNG"); break;
        case 3:
           m_pSharedImage = Fl_Shared_Image::get("Img/Customized.PNG"); break;
        case 4:
           m_pSharedImage = Fl_Shared_Image::get("Img/Back.PNG"); break;
        case 5:
           m_pSharedImage = Fl_Shared_Image::get("Img/Choice1.PNG"); break;
        case 6:
           m_pSharedImage = Fl_Shared_Image::get("Img/Choice2.PNG"); break;
        case 7:
           m_pSharedImage = Fl_Shared_Image::get("Img/Restart.PNG"); break;
        }
        image(m_pSharedImage->copy(w(),h()));
        redraw();
    }
