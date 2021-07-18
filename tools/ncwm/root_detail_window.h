#include <ncurses.h>

#include "window.h"

#ifndef _NCWM_ROOT_DETAIL_WINDOW_H
#define _NCWM_ROOT_DETAIL_WINDOW_H

ncwm_window root_detail_window();

void root_detail_window_clear();

void root_detail_window_refresh();

void root_detail_window_set_focus();

#endif /* _NCWM_ROOT_DETAIL_WINDOW_H */
