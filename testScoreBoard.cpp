#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "../ScoreBoard.h"

int main (int argc, char ** argv)
{
  Fl_Window *window;

  window = new Fl_Window (1200, 1000);
  ScoreBoard* scb = new ScoreBoard { 0 , 0 , 1 };
  //scb -> add_score1();
  //scb -> change_turn();
  window -> redraw();

  window->end ();
  window->show (argc, argv);

  return(Fl::run());
}
