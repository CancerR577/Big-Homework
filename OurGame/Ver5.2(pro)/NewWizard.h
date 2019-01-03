#ifndef NEWWIZARD_H_INCLUDED
#define NEWWIZARD_H_INCLUDED

#include <FL/Fl_Wizard.H>
#include <FL/Fl_Shared_Image.H>
#include <iostream>

class NewWizard : public Fl_Wizard
{
public:
    NewWizard(int x, int y, int W, int H, const char* name) : Fl_Wizard(x,y,W,H,name)
    {
        fl_register_images();
        m_pSharedImage = Fl_Shared_Image::get("Wizard.PNG");

        switch ( m_pSharedImage->fail() ) {
        case Fl_Image::ERR_NO_IMAGE:
        case Fl_Image::ERR_FILE_ACCESS:
            std::cerr << "not open\n";
        case Fl_Image::ERR_FORMAT:
            std::cerr << "error format!\n";
    }
        image(m_pSharedImage->copy(W,H));
        redraw();
    }

private:
    Fl_Shared_Image* m_pSharedImage;
};

#endif // NEWWIZARD_H_INCLUDED
