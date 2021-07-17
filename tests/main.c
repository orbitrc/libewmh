#include <stdlib.h>
#include <stdio.h>

#include <libewmh/icccm.h>
#include <libewmh/ewmh.h>

int main(int argc, char *argv[])
{
    uint32_t w = strtol(argv[1], NULL, 0);

    char *wm_client_machine = NULL;
    uint32_t net_number_of_desktops = 0;

    /*========================*/
    /* Root window properties */
    /*========================*/
    printf("Root window\n");

    /* Get root window properties */
    net_number_of_desktops = ewmh_net_number_of_desktops();

    printf("_NET_NUMBER_OF_DESKTOPS: %d\n", net_number_of_desktops);

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
