#ifndef _SCOREBOARD_H_
#define _SCOREBOARD_H_

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <Fl/Fl_Value_Output.H>

class ScoreBoard
{
public:
    ScoreBoard ( int s1 , int s2 , int t );
    void add_score1 ();
    void add_score2 ();
    void change_turn ();

private:
    int score1;
    int score2;
    int whoseturn;
    Fl_Value_Output* scorebox1;
    Fl_Value_Output* scorebox2;
    Fl_Value_Output* turnbox;
};

#endif//ScordBoard.h
