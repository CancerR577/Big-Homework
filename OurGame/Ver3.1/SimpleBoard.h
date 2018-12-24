#ifndef _SIMPLEBOARD_H_
#define _SIMPLEBOARD_H_

#include "EnterBox.h"
#include "Squares.h"
#include "Point.h"

class SimpleBoard : public Squares
{
public:
    SimpleBoard(int r, int c,StartAndEnd* sae);
    int getDegTable(int i, int j) { return DegTable[i][j]; }
    void setDegTable(int i, int j, int d) { DegTable[i][j] = d; }
private:
    int **DegTable;//not yet used
};

#endif // _SIMPLEBOARD_H_
