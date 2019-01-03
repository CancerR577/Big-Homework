#include <FL/fl_ask.H>
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
#include "StartAndEnd.h"



void CloseTheWindow(Fl_Widget *a,StartAndEnd *w)
{
    w->bw->~Fl_Widget();
    w->restart();
}

void RestartTheGame(Fl_Widget *a,StartAndEnd *w)
{
    w->bw->~Fl_Widget();
    w->game_start(w->get_rownum(),w->get_colnum(),w->get_type());
}

StartAndEnd::StartAndEnd ()
{
    rownum = 0;
    colnum = 0;
    totel = 0;
}

void StartAndEnd::game_start(int r,int c,int t)
{
    rownum = r;
    colnum = c;
    totel = r*c;
    type = t;

    bw = new Back_Window(1000,1000);

    SimpleBoard(rownum, colnum, this, type);

    NewButton* Quit = new  NewButton(800, 60, 150, 36, 1);
    NewButton* Restart = new  NewButton(800, 20, 150, 36, 7);
    Quit->callback((Fl_Callback*)CloseTheWindow,this);
    Restart->callback((Fl_Callback*)RestartTheGame,this);

    bw->end();
    bw->show();
    Fl::run();
}


void StartAndEnd::game_over(int who)
{
    int hotspot = fl_message_hotspot();
    fl_message_hotspot(0);
    fl_message_title("Game Over!");
    int rep;
    switch (who){
    case 1 :
        rep = fl_choice("Winner:Player1.\nPlay again?","Replay","Reset", "Exit");
        break;
    case 2 :
        rep = fl_choice("Winner:Player2.\nPlay again?","Replay","Reset", "Exit");
        break;
    case 3 :
        rep = fl_choice("A draw.\nPlay again?","Replay","Reset", "Exit");
        break;
    }
    fl_message_hotspot(hotspot);
    if (rep==2){
        bw->~Fl_Widget();
    }
    else if (rep == 1){
        bw->~Fl_Widget();
        this ->restart();
    }
    else{
        bw->~Fl_Widget();
        this ->game_start(rownum,colnum,type);
    }

}

int StartAndEnd::get_totel()
{
    return totel;
}

int StartAndEnd::get_rownum()
{
    return rownum;
}

int StartAndEnd::get_colnum()
{
    return colnum;
}

int StartAndEnd::get_type()
{
    return type;
}

void StartAndEnd::restart()
{
    ///È«¾Öº¯Êý

    extern void start_game();

    start_game();
}

