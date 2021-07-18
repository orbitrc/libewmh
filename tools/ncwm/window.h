#ifndef _NCWM_WINDOW_H
#define _NCWM_WINDOW_H

#include <ncurses.h>

typedef struct {
    WINDOW *window;
    void *props;

    /* Methods */
    void (*clear_window)();
    void (*refresh_window)();
    void (*set_focus)();
} ncwm_window;

#endif /* _NCWM_WINDOW_H */
