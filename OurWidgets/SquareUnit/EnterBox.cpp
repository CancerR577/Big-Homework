#include "EnterBox.h"
#include <iostream>

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
                color(FL_RED);
                isable = false;//让这个Box不能再响应
                square->setdeg(square->getdeg() - 1);
                square->activation();
                if (square2)
                {
                    square2->setdeg(square2->getdeg() - 1);
                    square2->activation();
                }
                redraw();
                return 1;
        }
    }
}

void EnterBox::cb_activate(Fl_Widget*, void* v)
{
    ( (SquareUnit*)v )->cb_activate_i();
    std::cout << "haha";
}

void SquareUnit::cb_activate_i()
{
    this->setdeg(this->getdeg() - 1);
    std::cout << this->getdeg();
    if (this->getdeg() == 0)
    {
        SquareUnit::activation();
    }
}
