#include "main_window.h"

#include "root_detail_window.h"

#define MAIN_WINDOW_WIDTH 60
#define MAIN_WINDOW_HEIGHT 20

static ncwm_window self;

struct props {
    int index;
};

static struct props props;

ncwm_window main_window()
{
    self.window = newwin(MAIN_WINDOW_HEIGHT, MAIN_WINDOW_WIDTH, 3, 3);
    keypad(self.window, TRUE);

    start_color();

    /* Set methods */
    self.clear_window = main_window_clear;
    self.refresh_window = main_window_refresh;
    self.set_focus = main_window_set_focus;

    /* Set props */
    props.index = 0;
    self.props = (void*)(&props);

    /* Initial refresh */
    self.refresh_window();

    return self;
}

void main_window_clear()
{
    wclear(self.window);
    wrefresh(self.window);
}

void main_window_refresh()
{
    struct props *props = (struct props*)(self.props);
    printw("index: %d", props->index);

    box(self.window, 0, 0);
    // mvhline(1, 1, '-', 3);
    mvwprintw(self.window, 0, 3, " ncwm ");

    if (props->index == 0) {
        wattron(self.window, COLOR_PAIR(2));
        mvwprintw(self.window, 2, 2, "* ");
    }
    mvwprintw(self.window, 2, 3, "Root window");
    wattroff(self.window, COLOR_PAIR(2));

    /* Quit button */
    if (props->index == -1) {
        wattron(self.window, COLOR_PAIR(2));
    }
    mvwprintw(self.window, MAIN_WINDOW_HEIGHT - 2, 3, "Quit");
    wattroff(self.window, COLOR_PAIR(2));

    wrefresh(self.window);
}

void main_window_set_focus()
{
    struct props *props = (struct props*)(self.props);

    while (1) {
        int ch = getch();
        switch (ch) {
        case KEY_UP:
            self.clear_window();
            self.refresh_window();
            printw("KEY_UP");
            break;
        case KEY_DOWN:
            break;
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
        case '\t':
            if (props->index != -1) {
                props->index = -1;
            } else {
                props->index = 0;
            }
            self.clear_window();
            self.refresh_window();
            break;
        case '\n':
            if (props->index == -1) {
                return;
            }
            /* Root window */
            if (props->index == 0) {
                ncwm_window root_detail_win = root_detail_window();
                root_detail_win.set_focus();
                delwin(root_detail_win.window);
                self.clear_window();
                self.refresh_window();
            }
            break;
        default:
            break;
        }
    }
}
