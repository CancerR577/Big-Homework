#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

#include <FL/FL.H>
#include <FL/Fl_Widget.H>
#include <Fl/Fl_Value_Output.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>

#include "../GUI/StartAndEnd.h"

class ScoreBoard
{
public:
    ScoreBoard ( int s1 , int s2 , int t ,StartAndEnd* &sae);
    void add_score1 ();
    void add_score2 ();
    void change_turn ();
    void judge_totel ();
    void winner();

private:
    int score1;
    int score2;
    int totelsc;
    int whoseturn;
    Fl_Box* namelabel_1;
    Fl_Box* namelabel_2;
    Fl_Shared_Image* player1;
    Fl_Shared_Image* player2;
    StartAndEnd* sbsae;
    Fl_Value_Output* scorebox1;
    Fl_Value_Output* scorebox2;
    Fl_Value_Output* turnbox;
};

#endif//ScordBoard.h
