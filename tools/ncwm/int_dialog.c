#include "int_dialog.h"

#include <stdbool.h>

static ncwm_dialog self;

struct props {
    const char *title;
    int value;
    bool ok;
};

struct props props;

void int_dialog_clear();
void int_dialog_refresh();

int int_dialog(const char *title, int val)
{
    self.window = newwin(INT_DIALOG_HEIGHT, INT_DIALOG_WIDTH,
        (LINES - INT_DIALOG_HEIGHT) / 2, (COLS - INT_DIALOG_WIDTH) / 2);
    keypad(self.window, TRUE);

    start_color();

    /* Set props */
    props.title = title;
    props.value = val;
    props.ok = false;
    self.props = (void*)(&props);

    /* Initial refresh */
    int_dialog_refresh();

    /* Loop */
    struct props *props = (struct props*)(self.props);

    while (1) {
        int ch = getch();
        switch (ch) {
        case KEY_UP:
            props->value += 1;
            int_dialog_clear();
            int_dialog_refresh();
            break;
        case KEY_DOWN:
            if (props->value > 0) {
                props->value -= 1;
                int_dialog_clear();
                int_dialog_refresh();
            }
            break;
        case '\t':
            props->ok = !(props->ok);
            int_dialog_clear();
            int_dialog_refresh();
            break;
        case '\n':
            delwin(self.window);
            if (props->ok) {
                return props->value;
            } else {
                return -1;
            }
        default:
            break;
        }
    }
}

void int_dialog_clear()
{
    wclear(self.window);
    wrefresh(self.window);
}

void int_dialog_refresh()
{
    struct props *props = (struct props*)(self.props);

    box(self.window, 0, 0);
    mvwprintw(self.window, 0, 3, " %s ", props->title);

    mvwprintw(self.window, 2, 3, "Value: ");
    mvwprintw(self.window, 2, 10, "%d", props->value);

    /* Ok/Cancel buttons */
    if (!(props->ok)) {
        wattron(self.window, COLOR_PAIR(2));
    }
    mvwprintw(self.window, INT_DIALOG_HEIGHT - 2, 3, "Cancel");
    wattroff(self.window, COLOR_PAIR(2));
    if (props->ok) {
        wattron(self.window, COLOR_PAIR(2));
    }
    mvwprintw(self.window, INT_DIALOG_HEIGHT - 2, 10, "Ok");
    wattroff(self.window, COLOR_PAIR(2));

    wrefresh(self.window);
}
