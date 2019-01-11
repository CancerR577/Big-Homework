#ifndef DOTBOX_H_INCLUDED
#define DOTBOX_H_INCLUDED

#include <FL/FL.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Box.H>

class DotBox : public Fl_Box
{
public:
    DotBox(int X = 50,int Y = 100,int W = 15,int H = 15, int choice = 0);
private:
    Fl_Shared_Image* m_pSharedImage;
 };

#endif // DOTBOX_H_INCLUDED

