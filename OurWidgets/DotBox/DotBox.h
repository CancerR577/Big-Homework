#ifndef ENTERBOX_H_INCLUDED
#define ENTERBOX_H_INCLUDED
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Shared_Image.H>
 void set_level() {}; // unaccomplished
enum Hard_level{easy, normal, hard};
void creat_dot(Hard_level l);
 class EnterBox : public Fl_Box
{
 public:
     int handle(int e)
     {
         if (!enable) return 0;//������ĳ��Box������ˣ��Ͳ�������Ӧ
        switch (e)
        {
            case  FL_ENTER://���������
                 color(FL_DARK_MAGENTA);
                 redraw();
                 return 1;
            case  FL_LEAVE://����ƿ�
                  color(FL_GRAY);
                  redraw();
                  return 1;
             case FL_PUSH:
                switch (Fl::event_button())
                {
                case FL_LEFT_MOUSE:
                    fl_register_images();
                    m_pSharedImage = Fl_Shared_Image::get("work.PNG");
                    image(m_pSharedImage->copy(w(),h()+15));
                    enable = false;//�����Box��������Ӧ
                    redraw();
                    return 1;
             }
             break;
         }
     }

    EnterBox(int x, int y, int w, int h, const char *l, bool ee ) : Fl_Box(x,y,w,h,l), enable{ee} {}
 private:
    Fl_Shared_Image* m_pSharedImage;//ͼƬ
    bool enable;
};
 class DotBox : public Fl_Box
{
public:
    DotBox(int X = 25,int Y = 50,int W = 10,int H = 10):Fl_Box(X,Y,W,H)
    {
        fl_register_images();
        m_pSharedImage = Fl_Shared_Image::get("work.PNG");
        image(m_pSharedImage->copy(w(),h()));
        redraw();
    }
private:
    Fl_Shared_Image* m_pSharedImage;
 };
 void creat_dot(Hard_level l, DotBox* ar[][6])
{
    switch(l){
    case easy:
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ar[i][j] = new DotBox(25 + 70*i,50 + 70*j,10,10);
            }
         }
    break;
    case normal:
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                ar[i][j] = new DotBox(25 + 70*i,50 + 70*j,10,10);
            }
         }
    break;
    case hard:
       for(int i=0; i<6; i++)
        {
            for(int j=0; j<6; j++)
            {
                ar[i][j] = new DotBox(25 + 70*i,50 + 70*j,10,10);
            }
         }
    }
}


#endif // ENTERBOX_H_INCLUDED