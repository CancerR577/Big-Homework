#ifndef _R_BOX_H_
#define _R_BOX_H_

#include <FL/FL.H>

#define R_BOX FL_FREE_BOXTYPE

void R_draw(int x,int y, int r, int u, Fl_Color c)
{
    fl_color(c);
    fl_line_style(FL_DASH,5);
    fl_circle(988,y + 60, 55);
}

#endif
