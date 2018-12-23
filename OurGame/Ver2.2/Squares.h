#ifndef _SQUARES_H_
#define _SQUARES_H_

#include "SquareUnit.h"
#include "Point.h"
#include "ScoreBoard.h"
#include "DotBox.h"
class Squares
{
public:
    Squares(int r, int c,StartAndEnd* &sae);
    void AllChangePlayer();
    void plus_score1();
    void plus_score2();
protected:
    int row;
    int column;
    SquareUnit ***s;
    DotBox ***d;
    ScoreBoard* scbd;
    StartAndEnd* sqsae;
};

#endif // _SQUARES_H_
