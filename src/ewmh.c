#include <stdlib.h>

#include <libewmh/base.h>
#include <libewmh/ewmh.h>
#include <libewmh/xcb/xcb.h>

EWMH_EXTERN_C_BEGIN

uint32_t ewmh_net_number_of_desktops()
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;
    void *val = NULL;
    uint32_t ret = 0;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        screen->root,
        "_NET_NUMBER_OF_DESKTOPS",
        XCB_ATOM_CARDINAL
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn,
        cookie,
        NULL
    );
    val = xcb_get_property_value(reply);
    ret = *((uint32_t*)val);

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

EWMH_EXTERN_C_END
