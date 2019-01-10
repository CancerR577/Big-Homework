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


Fl_Wizard* wiz = 0;                   //翻页区域初始化

SliderInput* sirow=0;                 //滚动条：行初始化

SliderInput* sicol=0;                 //滚动条：列初始化

SliderInput* sitype=0;                //滚动条：模式初始化

const int MAX = 8;                          //最大行列值：6

const int MIN = 2;                          //最小行列值：2

const int DEAFULT = 4;                      //默认行列值：4

int mode=1;

void next(Fl_Widget*,void*){wiz->next();}   //向下翻页

void prev(Fl_Widget*,void*){wiz->prev();}   //向上翻页

void modef1(Fl_Widget*,void*){mode=1;wiz->next();}

void modef2(Fl_Widget*,void*){mode=2;wiz->next();}


void R_draw(int x,int y, int r, int u, Fl_Color c)
{
    fl_color(c);
    fl_line_style(FL_DASH,5);
    fl_circle(988,y + 60, 55);
}



///默认模式
void deafult_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(DEAFULT,DEAFULT,mode);
    w->end();
}




///自定义模式
void customize_run(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(sirow->value(),sicol->value(),mode);
    w->end();
}



///关闭窗口
void clo(Fl_Widget *a,Fl_Window* w){
    w->begin();
    w->~Fl_Group();                    //点击quit结束
    w->end();
}


///开始界面
void start_game(){
    Back_Window* w = new Back_Window(500,405,"Game");
    wiz = new Fl_Wizard(0,0,500,405," ");
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,1);
        NewButton* Start = new NewButton(160,180, 180, 43, 0);//小窗口显示start
        NewButton* Quit = new  NewButton(160, 250, 180, 43, 1);//小窗口显示quit
        Start->callback(next);//点击start进入回调函数
        Quit->callback((Fl_Callback*)clo,w);//点击quit进入回调函数
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
        bac->callback(prev);//点击back
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,3);
        NewButton* dft = new NewButton(160, 180, 180, 43, 2);//创建deafult按钮
        NewButton* ctm = new NewButton(160, 250, 180, 43, 3);//创建customize按钮
        NewButton* bac = new NewButton(340,30, 140, 34, 4);//创建back按钮
        dft->callback((Fl_Callback*) deafult_run,w);//点击deafult
        ctm->callback(next);//点击customize
        bac->callback(prev);//点击back
        Gr->end();
    }
    {
        Fl_Group* Gr = new Fl_Group(0,0,500,405," ");
        DotBox* Back = new DotBox(0,0,500,405,4);
        NewButton* bac = new NewButton(340,30, 140, 34, 4);//创建back按钮
        sirow = new SliderInput(160,180,200,30,"row:");
        sicol = new SliderInput(160,250,200,30,"column:");
        sirow->bounds(MIN,MAX);       // set min/max for slider
        sirow->value(4);
        sicol->bounds(MIN,MAX);       // set min/max for slider
        sicol->value(4);
        NewButton* Start = new NewButton(160,300, 180, 43, 0);//创建Start按钮
        Start->callback((Fl_Callback*)customize_run,w);//按照自定义值开始游戏
        bac->callback(prev);//返回
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

