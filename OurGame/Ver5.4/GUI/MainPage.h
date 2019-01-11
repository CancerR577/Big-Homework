#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_

#include <FL/fl_draw.H>
#include <FL/Fl_Wizard.H>

#include "../Board/SimpleBoard.h"
#include "Back_window.h"
#include "StartAndEnd.h"
#include "Newbutton.h"
#include "SliderInput.h"

void next(Fl_Widget*,void*);   ///向下翻页
void prev(Fl_Widget*,void*);   ///向上翻页
void modef1(Fl_Widget*,void*);
void modef2(Fl_Widget*,void*);

void deafult_run(Fl_Widget *a,Fl_Window* w);        ///默认模式
void customize_run(Fl_Widget *a,Fl_Window* w);      ///自定义模式
void clo(Fl_Widget *a,Fl_Window* w);                ///关闭窗口
void start_game();                                  ///开始界面

#endif
