#include "SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>
#include <FL/fl_draw.H>

void deafult(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(4,4);
    w->end();
}

void customize(Fl_Widget *a,Fl_Window* w){
    w->begin();
    //StartAndEnd* sae = new StartAndEnd;
    //w->~Fl_Window();
    //sae->game_start(0,0);
    w->end();
}

void goback(Fl_Widget* s,Fl_Widget* a){
    s->hide();
    a->show();
}

void con(Fl_Widget *a,Fl_Window* w){
    w->begin();
    a->hide();                   //删除start按钮（暂时不知道如何删另一个）
    //b->~Fl_Widget();
    Fl_Button* dft = new Fl_Button(250, 50, 105, 25, "DEAFULT");//创建deafult按钮
    Fl_Button* ctm = new Fl_Button(250, 80, 105, 25, "CUSTOMIZE");//创建customize按钮
    Fl_Button* bac = new Fl_Button(250, 130, 105, 25, "BACK");//创建back按钮
    dft->callback((Fl_Callback*) deafult,w);//点击deafult
    ctm->callback((Fl_Callback*) customize,w);//点击customize
    bac->callback((Fl_Callback*) goback,a);
    w->end();
}

void clo(Fl_Widget *a,Fl_Window* w){
    w->begin();
    w->~Fl_Group();                    //点击quit结束
    w->end();
}


void start_game(){
    Fl_Window* w = new Fl_Window(400, 200,"Game");
    Fl_Button* Start = new Fl_Button(85, 50, 105, 25, "START");//小窗口显示start
    Fl_Button* Quit = new Fl_Button(85, 80, 105, 25, "QUIT");//小窗口显示quit
    Start->callback((Fl_Callback*) con,w);//点击start进入回调函数
    Quit->callback((Fl_Callback*) clo,w);//点击quit进入回调函数
    w->end();
    w->show();
}

void R_draw(int x,int y, int r, int u, Fl_Color c)
{
    fl_color(c);
    fl_line_style(FL_DASH,5);
    fl_circle(788,y + 60, 55);
}

#define R_BOX FL_FREE_BOXTYPE

int main()
{
    Fl::set_boxtype(R_BOX,R_draw,1,1,2,2);
    start_game();
    return Fl::run();
}

