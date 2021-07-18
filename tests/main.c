#include <stdlib.h>
#include <stdio.h>

#include <libewmh/icccm.h>
#include <libewmh/ewmh.h>

int main(int argc, char *argv[])
{
    uint32_t w = strtol(argv[1], NULL, 0);

    char *wm_client_machine = NULL;
    uint32_t net_number_of_desktops = 0;
    uint32_t net_current_desktop = 0;
    uint32_t net_active_window = 0;

    /*========================*/
    /* Root window properties */
    /*========================*/
    printf("Root window\n");

    /* Get root window properties */
    net_number_of_desktops = ewmh_net_number_of_desktops();
    net_current_desktop = ewmh_net_current_desktop();
    net_active_window = ewmh_net_active_window();

    printf("_NET_NUMBER_OF_DESKTOPS:    %d\n", net_number_of_desktops);
    printf("_NET_CURRENT_DESKTOP:       %d\n", net_current_desktop);
    printf("_NET_ACTIVE_WINDOW:         %#010x\n", net_active_window);

    /*===================*/
    /* Window properties */
    /*===================*/
    printf("Window id: %d\n", w);

    /* Get window properties */
    wm_client_machine = icccm_wm_client_machine(w);

    printf("WM_CLIENT_MACHINE: \"%s\"\n", wm_client_machine);

    /* Clean */
    free(wm_client_machine);

    return 0;
}
