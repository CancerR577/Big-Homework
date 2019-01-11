#include "DotBox.h"

DotBox::DotBox(int X, int Y, int W, int H, int choice)
    : Fl_Box(X,Y,W,H)
    {
        fl_register_images();
        switch(choice){
        case 0:
            m_pSharedImage = Fl_Shared_Image::get("Img/work4.PNG");
            break;
        case 1:
            m_pSharedImage = Fl_Shared_Image::get("Img/Wizard.PNG");
            break;
        case 3:
            m_pSharedImage = Fl_Shared_Image::get("Img/Wizard3.PNG");
            break;
        case 4:
            m_pSharedImage = Fl_Shared_Image::get("Img/Wizard4.PNG");
            break;
        }
        image(m_pSharedImage->copy(w(),h()));
        redraw();
    }
