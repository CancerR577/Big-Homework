#include "EnterBox.h"
#include <iostream>

inline int EnterBox::handle(int e)
{
    if (!isable) return 0;//������ĳ��Box������ˣ��Ͳ�������Ӧ
    switch (e)
    {
        case  FL_ENTER://���������
             color(FL_GREEN);
             redraw();
             return 1;
        case  FL_LEAVE://����ƿ�
             color(FL_GRAY);
             redraw();
             return 1;
        case FL_PUSH:
            switch (Fl::event_button())
            {
            case FL_LEFT_MOUSE:
                color(FL_RED);
                isable = false;//�����Box��������Ӧ
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
