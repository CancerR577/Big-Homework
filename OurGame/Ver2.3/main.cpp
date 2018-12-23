#include "SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <Fl/Enumerations.H>


int main()
{
    const StartAndEnd* sae = new StartAndEnd;
    return Fl::run();
}

