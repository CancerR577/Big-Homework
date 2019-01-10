#include "ScoreBoard.h"
#include "StartAndEnd.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Widget.H>
#define R_BOX FL_FREE_BOXTYPE

class Circle_Box : public Fl_Box
{
public:
    Circle_Box(Fl_Boxtype b, int x, int y, int w, int h, const char* l = 0) : Fl_Box(b, x , y, w, h, l)
    {

    }
};

ScoreBoard::ScoreBoard ( int s1, int s2 , int p ,StartAndEnd* &sae)
    : score1 { s1 }
    , score2 { s2 }
    , totelsc {sae->get_totel()}
    , whoseturn { p }
    , sbsae { sae }
{
    namelabel_1 = new Circle_Box(R_BOX,930 ,150 , 120 , 120);
    namelabel_2 = new Circle_Box(R_BOX,930 ,300 , 120 , 120);
    fl_register_images();
    player1 = Fl_Shared_Image::get("rook.PNG");
    player2 = Fl_Shared_Image::get("queen.PNG");
    namelabel_1->image(player1->copy(80,80));
    namelabel_1->color(FL_BLACK);
    namelabel_1->redraw();
    namelabel_2->image(player2->copy(80,80));
    namelabel_2->redraw();

    scorebox1 = new Fl_Value_Output { 1100 , 200 , 50 , 50 };
    scorebox2 = new Fl_Value_Output { 1100 , 350 , 50, 50 };

    scorebox1 -> value ( score1);
    scorebox1 -> textcolor ( FL_BLACK );
    scorebox1 -> textsize ( 30 );

    scorebox2 -> value ( score2 );
    scorebox2 -> textcolor ( FL_DARK_BLUE );
    scorebox2 -> textsize ( 30 );
}

void ScoreBoard::judge_totel()
{
    int nowtotel {score1 + score2};
    if(nowtotel == totelsc){
        this ->winner ();
    }
}

void ScoreBoard::add_score1 ()
{
    score1 ++ ;
    scorebox1 -> value ( score1 );
    scorebox1 -> textcolor ( FL_BLACK );
    scorebox1 -> textsize ( 30 );
    this ->judge_totel ();
}


void ScoreBoard::add_score2 ()
{
    score2 ++;
    scorebox2 -> value ( score2 );
    scorebox2 -> textcolor ( FL_DARK_BLUE );
    scorebox2 -> textsize ( 30 );
    this ->judge_totel();
}


void ScoreBoard::change_turn ()
{
    switch( whoseturn ){
    case 1 :
        whoseturn = 2;
        namelabel_1->color(FL_GRAY);
        namelabel_2->color(FL_BLACK);
        namelabel_1->redraw();
        namelabel_2->redraw();
        break;

    case 2 :
        whoseturn = 1;
        namelabel_2->color(FL_GRAY);
        namelabel_1->color(FL_BLACK);
        namelabel_1->redraw();
        namelabel_2->redraw();
        break;
    }
}

void ScoreBoard :: winner ()
{
    if(score1 > score2){
        sbsae ->game_over(1);
        return;
    }
    if(score1 < score2){
        sbsae ->game_over(2);
        return;
    }
    if(score1 == score2){
        sbsae ->game_over(3);
        return;
    }
}
