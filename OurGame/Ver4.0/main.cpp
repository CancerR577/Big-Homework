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
    a->hide();                   //ɾ��start��ť����ʱ��֪�����ɾ��һ����
    //b->~Fl_Widget();
    Fl_Button* dft = new Fl_Button(250, 50, 105, 25, "DEAFULT");//����deafult��ť
    Fl_Button* ctm = new Fl_Button(250, 80, 105, 25, "CUSTOMIZE");//����customize��ť
    Fl_Button* bac = new Fl_Button(250, 130, 105, 25, "BACK");//����back��ť
    dft->callback((Fl_Callback*) deafult,w);//���deafult
    ctm->callback((Fl_Callback*) customize,w);//���customize
    bac->callback((Fl_Callback*) goback,a);
    w->end();
}

void clo(Fl_Widget *a,Fl_Window* w){
    w->begin();
    w->~Fl_Group();                    //���quit����
    w->end();
}


void start_game(){
    Fl_Window* w = new Fl_Window(400, 200,"Game");
    Fl_Button* Start = new Fl_Button(85, 50, 105, 25, "START");//С������ʾstart
    Fl_Button* Quit = new Fl_Button(85, 80, 105, 25, "QUIT");//С������ʾquit
    Start->callback((Fl_Callback*) con,w);//���start����ص�����
    Quit->callback((Fl_Callback*) clo,w);//���quit����ص�����
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

