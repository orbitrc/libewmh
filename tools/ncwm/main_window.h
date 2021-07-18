#include <ncurses.h>

#include "window.h"

#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

ncwm_window main_window();

void main_window_clear();

void main_window_refresh();

void main_window_set_focus();

#endif /* _MAIN_WINDOW_H */
