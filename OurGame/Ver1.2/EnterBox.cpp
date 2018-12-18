#include "EnterBox.h"

inline int EnterBox::handle(int e)
{
    if (!isable) return 0;//如果这个某个Box被点过了，就不能再响应
    switch (e)
    {
        case  FL_ENTER://鼠标移上来
             color(FL_GREEN);
             redraw();
             return 1;
        case  FL_LEAVE://鼠标移开
             color(FL_GRAY);
             redraw();
             return 1;
        case FL_PUSH:
            switch (Fl::event_button())
            {
            case FL_LEFT_MOUSE:
                color(FL_BLACK);
                   fl_register_images();
                   eBox_pic = Fl_Shared_Image::get("work2.PNG");
                   image(eBox_pic->copy(w(),h()));
                   redraw();
                isable = false;//让这个Box不能再响应
                if (square2)
                {
                    square->setdeg(square->getdeg() - 1);
                    square2->setdeg(square2->getdeg() - 1);
                    square->activation();
                    square2->activation2();
                }
                else
                {
                    square->setdeg(square->getdeg() - 1);
                    square->activation();
                }
                redraw();
                return 1;
            }
            break;
    }
}
