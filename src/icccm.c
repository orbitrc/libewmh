#include <stdlib.h>
#include <string.h>

#include <libewmh/base.h>
#include <libewmh/icccm.h>
#include <libewmh/xcb/xcb.h>

EWMH_EXTERN_C_BEGIN

char* icccm_wm_client_machine(xcb_window_t w)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    char *val = NULL;
    unsigned int val_len = 0;
    char *ret = NULL;

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        w,
        "WM_CLIENT_MACHINE",
        XCB_ATOM_STRING
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn, cookie, NULL);
    val = xcb_get_property_value(reply);
    if (val != NULL) {
        val_len = strlen((char*)val);
        ret = malloc(val_len + 1);
        memcpy(ret, ((char*)val), (size_t)val_len);
    }

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

EWMH_EXTERN_C_END

