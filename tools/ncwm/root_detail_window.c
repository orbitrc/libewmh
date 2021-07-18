#include "root_detail_window.h"

#include <libewmh/ewmh.h>

#define ROOT_DETAIL_WINDOW_WIDTH 50
#define ROOT_DETAIL_WINDOW_HEIGHT 18

#define NET_NUMBER_OF_DESKTOPS_INDEX    0
#define NET_CURRENT_DESKTOP_INDEX       1
#define NET_ACTIVE_WINDOW_INDEX         2
#define INDEX_COUNT 3

#define FORMAT_DEC 0
#define FORMAT_HEX 1
#define FORMAT_STR 2

ncwm_window self;

struct props {
    int index;
};

static struct props props;

struct prop_tuple {
    int index;
    const char *name;
    void* (*getter)();
    int format;
};

struct prop_tuple prop_index[INDEX_COUNT] = {
    {
        NET_NUMBER_OF_DESKTOPS_INDEX,
        "_NET_NUMBER_OF_DESKTOPS",
        (void*)ewmh_net_number_of_desktops,
        FORMAT_DEC,
    },
    {
        NET_CURRENT_DESKTOP_INDEX,
        "_NET_CURRENT_DESKTOP",
        (void*)ewmh_net_current_desktop,
        FORMAT_DEC,
    },
    {
        NET_ACTIVE_WINDOW_INDEX,
        "_NET_ACTIVE_WINDOW",
        (void*)ewmh_net_active_window,
        FORMAT_HEX,
    },
};

ncwm_window root_detail_window()
{
    self.window = newwin(
        ROOT_DETAIL_WINDOW_HEIGHT, ROOT_DETAIL_WINDOW_WIDTH,
        4, 6);
    keypad(self.window, TRUE);

    start_color();

    /* Set methods */
    self.clear_window = root_detail_window_clear;
    self.refresh_window = root_detail_window_refresh;
    self.set_focus = root_detail_window_set_focus;

    /* Set props */
    props.index = 0;
    self.props = (void*)(&props);

    /* Initial refresh */
    self.refresh_window();

    return self;
}

void root_detail_window_clear()
{
    wclear(self.window);
    wrefresh(self.window);
}

void root_detail_window_refresh()
{
    struct props *props = (struct props*)(self.props);

    /* Init window */
    box(self.window, 0, 0);
    mvwprintw(self.window, 0, 3, " Root window ");

    /* Set menu */
    for (int i = 0; i < INDEX_COUNT; ++i) {
        if (props->index == prop_index[i].index) {
            wattron(self.window, COLOR_PAIR(2));
            mvwprintw(self.window, 2 + i, 2, "*");
        }
        mvwprintw(self.window, 2 + i, 4, prop_index[i].name);
        /* Value */
        if (prop_index[i].format == FORMAT_DEC) {
            uint32_t val = ((uint64_t)(prop_index[i].getter()));
            mvwprintw(self.window, 2 + i, 40, "%d", val);
        }
        if (prop_index[i].format == FORMAT_HEX) {
            uint32_t val = ((uint64_t)(prop_index[i].getter()));
            mvwprintw(self.window, 2 + i, 40, "%#010x", val);
        }
        wattroff(self.window, COLOR_PAIR(2));
    }

    /* Quit button */
    if (props->index == -1) {
        wattron(self.window, COLOR_PAIR(2));
    }
    mvwprintw(self.window, ROOT_DETAIL_WINDOW_HEIGHT - 2, 3, "Quit");
    wattroff(self.window, COLOR_PAIR(2));

    wrefresh(self.window);
}

void root_detail_window_set_focus()
{
    struct props *props = (struct props*)(self.props);

    while (1) {
        int ch = getch();
        switch (ch) {
        case KEY_UP:
            if (props->index > 0) {
                props->index -= 1;
                self.clear_window();
                self.refresh_window();
            }
            break;
        case KEY_DOWN:
            if (props->index < INDEX_COUNT - 1) {
                props->index += 1;
                self.clear_window();
                self.refresh_window();
            }
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
                printw("INDEX is QUIT");
                return;
            }
            break;
        default:
            break;
        }
    }
}
