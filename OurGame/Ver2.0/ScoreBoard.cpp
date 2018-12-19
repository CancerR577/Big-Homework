#include "ScoreBoard.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>

ScoreBoard::ScoreBoard ( int s1, int s2 , int p )
    : score1 { s1 }
    , score2 { s2 }
    , whoseturn { p }
{
    Fl_Box* namelabel1 = new Fl_Box ( 700 , 125 , 200 , 50 , "Player1");
    Fl_Box* namelabel2 = new Fl_Box ( 700 , 275 , 200 , 50 , "Player2");
    Fl_Box* turnlabel = new Fl_Box ( 700 , 425 , 200 , 50 , "It's turn of player ");

    namelabel1->box(FL_UP_BOX);
    namelabel1->labelsize( 35 );
    namelabel1->labelfont(FL_ITALIC);
    namelabel1->labeltype(FL_SHADOW_LABEL);

    namelabel2->box(FL_UP_BOX);
    namelabel2->labelsize( 35 );
    namelabel2->labelfont(FL_ITALIC);
    namelabel2->labeltype(FL_SHADOW_LABEL);

    turnlabel->box(FL_UP_BOX);
    turnlabel->labelsize( 25 );
    turnlabel->labelfont(FL_ITALIC);
    turnlabel->labeltype(FL_SHADOW_LABEL);

    scorebox1 = new Fl_Value_Output { 700 , 200 , 50 , 50 };
    scorebox2 = new Fl_Value_Output { 700 , 350 , 50, 50 };

    scorebox1 -> value ( score1);
    scorebox1 -> textcolor ( FL_BLUE );
    scorebox1 -> textsize ( 30 );

    scorebox2 -> value ( score2 );
    scorebox2 -> textcolor ( FL_RED );
    scorebox2 -> textsize ( 30 );

    turnbox = new Fl_Value_Output { 925 , 425 , 50, 50 };
    turnbox -> value ( whoseturn );
    turnbox -> textcolor ( FL_BLUE );
    turnbox -> textsize ( 30 );
}

void ScoreBoard::add_score1 ()
{
    score1 ++ ;
    scorebox1 -> value ( score1);
    scorebox1 -> textcolor ( FL_BLUE );
    scorebox1 -> textsize ( 30 );
}


void ScoreBoard::add_score2 ()
{
    score2 ++;
    scorebox2 -> value ( score2 );
    scorebox2 -> textcolor ( FL_RED );
    scorebox2 -> textsize ( 30 );
}


void ScoreBoard::change_turn ()
{
    switch( whoseturn ){
    case 1 :
        whoseturn = 2;
        turnbox -> value ( whoseturn );
        turnbox -> textcolor ( FL_RED );
        turnbox -> textsize ( 30 );
        turnbox -> redraw();
        break;

    case 2 :
        whoseturn = 1;
        turnbox -> value ( whoseturn );
        turnbox -> textcolor ( FL_BLUE );
        turnbox -> textsize ( 30 );
        turnbox -> redraw();
        break;
    }
}
