#include <stdio.h>

#include <ncurses.h>

#include "main_window.h"

void show_window(WINDOW *w);
void destroy_window(WINDOW *w);

int main(int argc, char *argv[])
{
    WINDOW *active_window;

    /* Initialize curses */
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    /* Set colors */
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color.\n");
        return 1;
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(1));
    clear();
    refresh();

    /* Create main window */
    ncwm_window main_win = main_window();
    // active_window = main_win;
    show_window(main_win.window);

    main_win.set_focus();

    endwin();

    return 0;
}

void show_window(WINDOW *w)
{
    wrefresh(w);
}

void destroy_window(WINDOW *w)
{
    delwin(w);
}
