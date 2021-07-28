#include <stdlib.h>
#include <stdio.h>

#include <libewmh/icccm.h>
#include <libewmh/ewmh.h>

int main(int argc, char *argv[])
{
    uint32_t w = strtol(argv[1], NULL, 0);

    char *wm_client_machine = NULL;
    char *net_wm_name = NULL;
    char *net_wm_visible_name = NULL;
    char *net_wm_icon_name = NULL;
    uint32_t net_wm_desktop = 0;

    ewmh_uint_list_t net_client_list;
    uint32_t net_number_of_desktops = 0;
    uint32_t net_current_desktop = 0;
    uint32_t net_active_window = 0;

    /*========================*/
    /* Root window properties */
    /*========================*/
    printf("Root window\n");

    /* Get root window properties */
    net_client_list = ewmh_net_client_list();
    net_number_of_desktops = ewmh_net_number_of_desktops();
    net_current_desktop = ewmh_net_current_desktop();
    net_active_window = ewmh_net_active_window();

    printf("_NET_CLIENT_LIST:\n");
    for (size_t i = 0; i < net_client_list.length; ++i) {
        printf("    %#010x\n", ewmh_uint_list_at(&net_client_list, i, NULL));
    }
    printf("_NET_NUMBER_OF_DESKTOPS:    %d\n", net_number_of_desktops);
    printf("_NET_CURRENT_DESKTOP:       %d\n", net_current_desktop);
    printf("_NET_ACTIVE_WINDOW:         %#010x\n", net_active_window);

    ewmh_uint_list_free(&net_client_list);

    /*===================*/
    /* Window properties */
    /*===================*/
    printf("Window id: %d\n", w);

    /* Get window properties */
    wm_client_machine = icccm_wm_client_machine(w);
    net_wm_name = ewmh_net_wm_name(w);
    net_wm_visible_name = ewmh_net_wm_visible_name(w);
    net_wm_icon_name = ewmh_net_wm_icon_name(w);
    net_wm_desktop = ewmh_net_wm_desktop(w);

    printf("WM_CLIENT_MACHINE:      \"%s\"\n", wm_client_machine);
    printf("_NET_WM_NAME:           \"%s\"\n", net_wm_name);
    printf("_NET_WM_VISIBLE_NAME:   \"%s\"\n", net_wm_visible_name);
    printf("_NET_WM_ICON_NAME:      \"%s\"\n", net_wm_icon_name);
    printf("_NET_WM_DESKTOP:        %d\n", net_wm_desktop);

    /* Clean */
    free(wm_client_machine);
    free(net_wm_name);
    free(net_wm_visible_name);
    free(net_wm_icon_name);

    return 0;
}
