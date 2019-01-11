#ifndef NEWBUTTON_H_INCLUDED
#define NEWBUTTON_H_INCLUDED

#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>

class NewButton : public Fl_Button
{
public:
    NewButton(int X, int Y, int W, int H, int choice);
private:
    Fl_Shared_Image* m_pSharedImage;
};

#endif // NEWBUTTON_H_INCLUDED
