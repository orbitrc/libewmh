#include <stdlib.h>
#include <string.h>

#include <libewmh/base.h>
#include <libewmh/xcb/xcb.h>

EWMH_EXTERN_C_BEGIN

xcb_atom_t ewmh_get_atom(xcb_connection_t *conn, const char *atom)
{
    xcb_intern_atom_cookie_t cookie = xcb_intern_atom(
        conn,
        1,
        strlen(atom),
        atom
    );
    xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply(conn, cookie, NULL);
    xcb_atom_t reply_atom = reply->atom;
    free(reply);

    return reply_atom;
}

xcb_get_property_cookie_t ewmh_get_property_cookie(xcb_connection_t *conn,
        xcb_window_t w, const char *prop, xcb_atom_t type)
{
    xcb_atom_t atom_prop = ewmh_get_atom(conn, prop);

    xcb_get_property_cookie_t cookie = xcb_get_property(
        conn,
        0,
        w,
        atom_prop,
        type,
        0,
        1024
    );

    return cookie;
}

void ewmh_change_property(xcb_connection_t *conn, uint8_t mode, xcb_window_t w,
        const char *prop, xcb_atom_t type, size_t data_len, void *data)
{
    xcb_atom_t atom = ewmh_get_atom(conn, prop);
    xcb_void_cookie_t cookie = xcb_change_property_checked(
        conn,
        mode,
        w,
        atom,
        type,
        32,
        data_len,
        data
    );
    xcb_flush(conn);

    xcb_generic_error_t *err = xcb_request_check(conn, cookie);
    if (err != NULL) {
        free(err);
    }
}

EWMH_EXTERN_C_END
