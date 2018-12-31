#include "EnterBox.h"
#include <iostream>

inline int EnterBox::handle(int e)
{
    if (!isable) return 0;//������ĳ��Box������ˣ��Ͳ�������Ӧ
    switch (e)
    {
        case  FL_ENTER://���������
             color(FL_DARK_BLUE);
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
                fl_register_images();
                if(w() > h()){
                    eBox_pic = Fl_Shared_Image::get("work_1.PNG");
                }
                else{
                    eBox_pic = Fl_Shared_Image::get("work_2.PNG");
                }
                image(eBox_pic->copy(w(),h()));
                redraw();
                isable = false;//�����Box��������Ӧ
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
