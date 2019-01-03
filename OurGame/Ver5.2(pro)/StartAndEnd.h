#ifndef STARTANDEND_H_
#define STARTANDEND_H_

#include "Back_window.h"

class StartAndEnd
{
public:
    StartAndEnd();
    void game_start(int r,int c,int t);
    void game_over(int who);
    int get_totel();
    int get_rownum();
    int get_colnum();
    int get_type();
    void restart();
    Back_Window* bw ;


private:
    int rownum;
    int colnum;
    int totel;
    int type;
};


#endif
