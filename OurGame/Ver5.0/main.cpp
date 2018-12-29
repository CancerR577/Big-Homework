#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Wizard.H>

#include "SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include "Newbutton.h"
#include "SliderInput.h"


Fl_Wizard* wiz = 0;                   //��ҳ�����ʼ��

SliderInput* sirow=0;                 //���������г�ʼ��

SliderInput* sicol=0;                 //���������г�ʼ��

const int MAX = 6;                          //�������ֵ��6

const int MIN = 2;                          //��С����ֵ��2

const int DEAFULT = 4;                      //Ĭ������ֵ��4


void next(Fl_Widget*,void*){wiz->next();}   //���·�ҳ

void prev(Fl_Widget*,void*){wiz->prev();}   //���Ϸ�ҳ





void R_draw(int x,int y, int r, int u, Fl_Color c)
{
    fl_color(c);
    fl_line_style(FL_DASH,5);
    fl_circle(788,y + 60, 55);
}




///Ĭ��ģʽ
void deafult_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(DEAFULT,DEAFULT);
    w->end();
}




///�Զ���ģʽ
void customize_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(sirow->value(),sicol->value());
    w->end();

}



//�رմ���
void clo(Fl_Widget *a,Fl_Window* w){
    w->begin();
    w->~Fl_Group();                    //���quit����
    w->end();
}




///��ʼ����
void start_game(){
    Back_Window* w = new Back_Window(370,300,"Game",1);
    wiz = new Fl_Wizard(0,0,370,300," ");
    {
        Fl_Group* Gr = new Fl_Group(0,0,370,300," ");
        NewButton* Start = new NewButton(100, 130, 150, 36, 0);//С������ʾstart
        NewButton* Quit = new  NewButton(100, 190, 150, 36, 1);//С������ʾquit
        Start->callback(next);//���start����ص�����
        Quit->callback((Fl_Callback*)clo,w);//���quit����ص�����
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,370,300," ");
        NewButton* dft = new NewButton(100, 110, 150, 36, 2);//����deafult��ť
        NewButton* ctm = new NewButton(100, 150, 150, 36, 3);//����customize��ť
        NewButton* bac = new NewButton(100, 190, 150, 36, 4);//����back��ť
        dft->callback((Fl_Callback*) deafult_run,w);//���deafult
        ctm->callback(next);//���customize
        bac->callback(prev);//���back
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,370,300," ");
        NewButton* bac = new NewButton(100, 240, 150, 36, 4);//����back��ť
        sirow = new SliderInput(80,40,200,30,"row:");
        sicol = new SliderInput(80,110,200,30,"column:");
        sirow->bounds(MIN,MAX);       // set min/max for slider
        sirow->value(4);
        sicol->bounds(MIN,MAX);       // set min/max for slider
        sicol->value(4);
        NewButton* Start = new NewButton(100, 170, 150, 36, 0);//����Start��ť
        Start->callback((Fl_Callback*)customize_run,w);//�����Զ���ֵ��ʼ��Ϸ
        bac->callback(prev);//����
        Gr->end();
    }
    w->end();
    w->show();
}


#define R_BOX FL_FREE_BOXTYPE

int main()
{
    Fl::set_boxtype(R_BOX,R_draw,1,1,2,2);
    start_game();
    return Fl::run();
}

