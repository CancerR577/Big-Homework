#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_PNG_Image.H>

#include "SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include "Newbutton.h"
#include "SliderInput.h"


Fl_Wizard* wiz = 0;                   //��ҳ�����ʼ��

SliderInput* sirow=0;                 //���������г�ʼ��

SliderInput* sicol=0;                 //���������г�ʼ��

SliderInput* sitype=0;                //��������ģʽ��ʼ��

const int MAX = 8;                          //�������ֵ��6

const int MIN = 2;                          //��С����ֵ��2

const int DEAFULT = 4;                      //Ĭ������ֵ��4

int mode=1;

void next(Fl_Widget*,void*){wiz->next();}   //���·�ҳ

void prev(Fl_Widget*,void*){wiz->prev();}   //���Ϸ�ҳ

void modef1(Fl_Widget*,void*){mode=1;wiz->next();}

void modef2(Fl_Widget*,void*){mode=2;wiz->next();}


void R_draw(int x,int y, int r, int u, Fl_Color c)
{
    fl_color(c);
    fl_line_style(FL_DASH,5);
    fl_circle(988,y + 60, 55);
}



///Ĭ��ģʽ
void deafult_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(DEAFULT,DEAFULT,mode);
    w->end();
}




///�Զ���ģʽ
void customize_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(sirow->value(),sicol->value(),mode);
    w->end();
}



///�رմ���
void clo(Fl_Widget *a,Fl_Window* w){
    w->begin();
    w->~Fl_Group();                    //���quit����
    w->end();
}


///��ʼ����
void start_game(){
    Back_Window* w = new Back_Window(500,405,"Game");
    wiz = new Fl_Wizard(0,0,500,405," ");
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,1);
        NewButton* Start = new NewButton(160,180, 180, 43, 0);//С������ʾstart
        NewButton* Quit = new  NewButton(160, 250, 180, 43, 1);//С������ʾquit
        Start->callback(next);//���start����ص�����
        Quit->callback((Fl_Callback*)clo,w);//���quit����ص�����
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,3);
        NewButton* mode1 = new NewButton(100, 200, 90, 90, 5);
        NewButton* mode2 = new NewButton(240, 200, 90, 90, 6);
        NewButton* bac = new NewButton(340,30, 140, 34, 4);
        mode1->callback(modef1);
        mode2->callback(modef2);
        bac->callback(prev);//���back
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,3);
        NewButton* dft = new NewButton(160, 180, 180, 43, 2);//����deafult��ť
        NewButton* ctm = new NewButton(160, 250, 180, 43, 3);//����customize��ť
        NewButton* bac = new NewButton(340,30, 140, 34, 4);//����back��ť
        dft->callback((Fl_Callback*) deafult_run,w);//���deafult
        ctm->callback(next);//���customize
        bac->callback(prev);//���back
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,4);
        NewButton* bac = new NewButton(340,30, 140, 34, 4);//����back��ť
        sirow = new SliderInput(160,180,200,30,"row:");
        sicol = new SliderInput(160,250,200,30,"column:");
        sirow->bounds(MIN,MAX);       // set min/max for slider
        sirow->value(4);
        sicol->bounds(MIN,MAX);       // set min/max for slider
        sicol->value(4);
        NewButton* Start = new NewButton(160,300, 180, 43, 0);//����Start��ť
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

