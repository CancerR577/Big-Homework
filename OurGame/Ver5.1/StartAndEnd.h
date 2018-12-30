#ifndef STARTANDEND_H_
#define STARTANDEND_H_

#include "Back_window.h"

class StartAndEnd
{
public:
    StartAndEnd();
    void game_start(int r,int c);
    void game_over(int who);
    int get_totel();

private:
    int rownum;
    int colnum;
    int totel;
    Back_Window* bw ;
};


#endif
