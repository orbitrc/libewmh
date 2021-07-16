#include <stdlib.h>
#include <stdio.h>

#include <libewmh/icccm.h>

int main(int argc, char *argv[])
{
    uint32_t w = strtol(argv[1], NULL, 0);

    char *wm_client_machine = NULL;

    printf("Window id: %d\n", w);

    /* Get properties */
    wm_client_machine = icccm_wm_client_machine(w);

    printf("WM_CLIENT_MACHINE: \"%s\"\n", wm_client_machine);

    /* Clean */
    free(wm_client_machine);

    return 0;
}
