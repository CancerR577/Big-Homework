#include "SquareUnit.h"
#include "Squares.h"
#include <iostream>

SquareUnit::SquareUnit(int x, int y, int w, int h, int d, int who, Squares* sqss)
        : Fl_Box(x,y,w,h)
        , deg{d}
        , PlayerNumber{who}
        , sqs{sqss}
        {
        }

int SquareUnit::getdeg() { return deg; }

void SquareUnit::setdeg(int d) { deg = d; }

void SquareUnit::changePlayer()
{
    switch (PlayerNumber)
    {
    case 1:
        PlayerNumber = 2;
        break;
    case 2:
        PlayerNumber = 1;
        break;
    }
}

void SquareUnit::activation()
{
    switch (deg)
    {
    case 0:
        switch (PlayerNumber)
        {
        case 1:
            fl_register_images();
            square_pic = Fl_Shared_Image::get("rook.PNG");
            image(square_pic->copy(w()-10,h()-10));
            redraw();
            sqs ->plus_score1();
            break;
        case 2:
            fl_register_images();
            square_pic = Fl_Shared_Image::get("queen.PNG");
            image(square_pic->copy(w(),h()));
            redraw();
            sqs ->plus_score2();
            break;
        }
        break;
    default:
        sqs->AllChangePlayer();
        std::cout<< "activation1" << std::endl;
        redraw();
        break;
    }
}

void SquareUnit::activation2()
{
    switch (deg)
    {
    case 0:
        switch (PlayerNumber)
        {
        case 1:
            fl_register_images();
            square_pic = Fl_Shared_Image::get("rook.PNG");
            image(square_pic->copy(w()-10,h()-10));
            redraw();
            sqs ->plus_score1();
            break;
        case 2:
            fl_register_images();
            square_pic = Fl_Shared_Image::get("queen.PNG");
            image(square_pic->copy(w(),h()));
            redraw();
            sqs ->plus_score2();
            break;
        }
        break;
    default:
        std::cout<< "activation2\n" << std::endl;
        redraw();
        break;
    }
}
