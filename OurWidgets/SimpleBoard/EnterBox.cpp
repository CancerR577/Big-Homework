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
                color(FL_BLACK);
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
