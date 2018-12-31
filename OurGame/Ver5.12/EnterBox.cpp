#include "EnterBox.h"
#include <iostream>

inline int EnterBox::handle(int e)
{
    if (!isable) return 0;//如果这个某个Box被点过了，就不能再响应
    switch (e)
    {
        case  FL_ENTER://鼠标移上来
             color(FL_DARK_BLUE);
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
                fl_register_images();
                if(w() > h()){
                    eBox_pic = Fl_Shared_Image::get("work_1.PNG");
                }
                else{
                    eBox_pic = Fl_Shared_Image::get("work_2.PNG");
                }
                image(eBox_pic->copy(w(),h()));
                redraw();
                isable = false;//让这个Box不能再响应
                if (square2)
                {
                    square->setdeg(square->getdeg() - 1);
                    square2->setdeg(square2->getdeg() - 1);
                    if (!(square->getdeg() && square2->getdeg()))
                    {
                        square->activation2();
                        square2->activation2();
                    }
                    else if (square->getdeg() && square2->getdeg())
                    {
                        square->activation();
                        square2->activation2();
                    }
                    else
                    {
                        if (square->getdeg() == 0)
                        {
                            square->activation2();
                            square2->activation();
                        }
                        else
                        {
                            square2->activation2();
                            square->activation();
                        }
                    }
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
