#ifndef _SQUARES_H_
#define _SQUARES_H_

#include "SquareUnit.h"
#include "Point.h"

class Squares
{
public:
    Squares(int r, int c);
    void AllChangePlayer();

protected:
    int row;
    int column;
    SquareUnit ***s;
};

#endif // _SQUARES_H_
