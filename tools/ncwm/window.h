#ifndef _NCWM_WINDOW_H
#define _NCWM_WINDOW_H

#include <ncurses.h>

#define DIALOG_TYPE_INT     0
#define DIALOG_TYPE_STR     1

#define INT_DIALOG_WIDTH    60
#define INT_DIALOG_HEIGHT   10

typedef struct {
    WINDOW *window;
    void *props;

    /* Methods */
    void (*clear_window)();
    void (*refresh_window)();
    void (*set_focus)();
    void* (*close)();
} ncwm_window;

typedef struct {
    WINDOW *window;
    void *props;

    /* Methods */
    void* (*open)();
} ncwm_dialog;


#endif /* _NCWM_WINDOW_H */
