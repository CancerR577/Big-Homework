#include <FL/Fl_Box.H>
#ifndef DOTBOX_H_INCLUDED
#define DOTBOX_H_INCLUDED

class DotBox : public Fl_Box
{
public:
    DotBox(int X = 50,int Y = 100,int W = 15,int H = 15):Fl_Box(X,Y,W,H)
    {
        fl_register_images();
        m_pSharedImage = Fl_Shared_Image::get("work4.PNG");
        image(m_pSharedImage->copy(w(),h()));
        redraw();
    }
private:
    Fl_Shared_Image* m_pSharedImage;
 };

#endif // DOTBOX_H_INCLUDED
