#include "StartAndEnd.h"
#include "SimpleBoard.h"
#include "Back_window.h"
#include <iostream>
#include <FL/fl_ask.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>

void CloseTheWindow(Fl_Widget *a,Fl_Window* w)
{
    w->begin();
    w->~Fl_Window();
    w->end();
}

StartAndEnd::StartAndEnd ()
{
    rownum = 0;
    colnum = 0;
    totel = 0;
    //game_start(0,0);ศฅต๔มห
}

void StartAndEnd::game_start(int r,int c)
{
    if(r == 0 || c == 0){
            std::cout << "Please input the number of rows and the number of columns." << '\n';
            std::cin >> r >> c;
    }

    rownum = r;
    colnum = c;
    totel = r*c;

    bw = new Back_Window(1000,700);

    SimpleBoard(rownum, colnum, this, 1);
    //SimpleBoard(rownum, colnum, this, 2);

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
        bw ->hide();
    }
    else if (rep == 1){
        bw -> hide();
        this ->game_start( 0 , 0 );
    }
    else{
        bw ->hide();
        this ->game_start(rownum,colnum);
    }

}

int StartAndEnd::get_totel()
{
    return totel;
}





