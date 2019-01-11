#include "NewWizard.h"

NewWizard::NewWizard(int x, int y, int W, int H, const char* name)
    : Fl_Wizard(x,y,W,H,name)
    {
        fl_register_images();
        m_pSharedImage = Fl_Shared_Image::get("Img/Wizard.PNG");
        image(m_pSharedImage->copy(W,H));
        redraw();
    }
