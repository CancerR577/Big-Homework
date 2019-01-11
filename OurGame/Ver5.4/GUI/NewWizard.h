#ifndef NEWWIZARD_H_INCLUDED
#define NEWWIZARD_H_INCLUDED

#include <FL/Fl_Wizard.H>
#include <FL/Fl_Shared_Image.H>

class NewWizard : public Fl_Wizard
{
public:
    NewWizard(int x, int y, int W, int H, const char* name);

private:
    Fl_Shared_Image* m_pSharedImage;
};

#endif // NEWWIZARD_H_INCLUDED
