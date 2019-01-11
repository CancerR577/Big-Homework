#include "GUI/MainPage.h"
#include "GUI/R_BOX.h"

int main()
{
    Fl::set_boxtype(R_BOX,R_draw,1,1,2,2);
    start_game();
    return Fl::run();
}

