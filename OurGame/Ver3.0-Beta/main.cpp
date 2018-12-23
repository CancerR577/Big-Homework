#include "SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>

void deafult(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(4,4);
    w->end();
}

void customize(Fl_Widget *a,Fl_Window* w){
    w->begin();
    StartAndEnd* sae = new StartAndEnd;
    w->~Fl_Window();
    sae->game_start(0,0);
    w->end();
}

void con(Fl_Widget *a,Fl_Window* w){
    w->begin();
    a->~Fl_Widget();                   //ɾ��start��ť����ʱ��֪�����ɾ��һ����
    //b->~Fl_Widget();
    Fl_Button* dft = new Fl_Button(250, 50, 105, 25, "DEAFULT");//����deafult��ť
    Fl_Button* ctm = new Fl_Button(250, 80, 105, 25, "CUSTOMIZE");//����customize��ť
    dft->callback((Fl_Callback*) deafult,w);//���deafult
    ctm->callback((Fl_Callback*) customize,w);//���customize
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

int main()
{
    start_game();
    return Fl::run();
}

