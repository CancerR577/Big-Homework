#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

#include <FL/fl_draw.H>
#include <FL/Fl_Wizard.H>

#include "../Board/SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include "Newbutton.h"
#include "SliderInput.h"

void next(Fl_Widget*,void*);   ///���·�ҳ
void prev(Fl_Widget*,void*);   ///���Ϸ�ҳ
void modef1(Fl_Widget*,void*);
void modef2(Fl_Widget*,void*);

void deafult_run(Fl_Widget *a,Fl_Window* w);        ///Ĭ��ģʽ
void customize_run(Fl_Widget *a,Fl_Window* w);      ///�Զ���ģʽ
void clo(Fl_Widget *a,Fl_Window* w);                ///�رմ���
void start_game();                                  ///��ʼ����

#endif
