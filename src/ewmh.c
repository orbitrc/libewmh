#include <stdlib.h>
#include <string.h>
#include <stdio.h> /* FOR DEBUG */

#include <libewmh/base.h>
#include <libewmh/ewmh.h>
#include <libewmh/xcb/xcb.h>

EWMH_EXTERN_C_BEGIN

char* _ewmh_string_property(uint32_t window, const char *prop);

/*=====================================*/
/* Root window properties and messages */
/*=====================================*/

ewmh_uint_list_t ewmh_net_client_list()
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;
    void *val = NULL;
    int val_len = 0;
    ewmh_uint_list_t ret = ewmh_uint_list_new();

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        screen->root,
        "_NET_CLIENT_LIST",
        XCB_ATOM_WINDOW
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn,
        cookie,
        NULL
    );
    val = xcb_get_property_value(reply);
    val_len = reply->length;

    for (int i = 0; i < val_len; ++i) {
        ewmh_uint_list_push(&ret, ((uint32_t*)val)[i]);
    }

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

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

void ewmh_set_net_number_of_desktops(uint32_t value)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    ewmh_change_property(
        conn,
        XCB_PROP_MODE_REPLACE,
        screen->root,
        "_NET_NUMBER_OF_DESKTOPS",
        XCB_ATOM_CARDINAL,
        1,
        (void*)(&value)
    );

    /* Free resources */
    xcb_disconnect(conn);
}

uint32_t ewmh_net_current_desktop()
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;
    void *val = NULL;
    uint32_t ret = 0;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        screen->root,
        "_NET_CURRENT_DESKTOP",
        XCB_ATOM_CARDINAL
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn, cookie, NULL);
    val = xcb_get_property_value(reply);
    ret = *((uint32_t*)val);

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

void ewmh_set_net_current_desktop(uint32_t value)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    ewmh_change_property(
        conn,
        XCB_PROP_MODE_REPLACE,
        screen->root,
        "_NET_CURRENT_DESKTOP",
        XCB_ATOM_CARDINAL,
        1,
        (void*)(&value)
    );

    /* Free resources */
    xcb_disconnect(conn);
}

uint32_t ewmh_net_active_window()
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;
    void *val = NULL;
    uint32_t ret = 0;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        screen->root,
        "_NET_ACTIVE_WINDOW",
        XCB_ATOM_WINDOW
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn, cookie, NULL);
    val = xcb_get_property_value(reply);
    ret = *((uint32_t*)val);

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

void ewmh_set_net_active_window(uint32_t window)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    xcb_screen_t *screen;

    screen = xcb_setup_roots_iterator(xcb_get_setup(conn)).data;

    ewmh_change_property(
        conn,
        XCB_PROP_MODE_REPLACE,
        screen->root,
        "_NET_ACTIVE_WINDOW",
        XCB_ATOM_WINDOW,
        1,
        (void*)(&window)
    );

    /* Free resources */
    xcb_disconnect(conn);
}

/*============================*/
/* Other root window messages */
/*============================*/

/*===============================*/
/* Application window properties */
/*===============================*/

char* ewmh_net_wm_name(uint32_t window)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    void *val = NULL;
    unsigned int val_len = 0;
    char *ret = NULL;
    xcb_atom_t utf8_string = ewmh_get_atom(conn, "UTF8_STRING");

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        window,
        "_NET_WM_NAME",
        utf8_string
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn, cookie, NULL);
    if (reply == NULL) {
        xcb_disconnect(conn);

        return NULL;
    }

    val = xcb_get_property_value(reply);
    if (val != NULL) {
        val_len = xcb_get_property_value_length(reply);
        ret = malloc(val_len + 1);
        memcpy(ret, ((char*)val), (size_t)val_len);
        ret[val_len] = '\0';
    }

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

char* ewmh_net_wm_visible_name(uint32_t window)
{
    return _ewmh_string_property(window, "_NET_WM_VISIBLE_NAME");
}

char* ewmh_net_wm_icon_name(uint32_t window)
{
    return _ewmh_string_property(window, "_NET_WM_ICON_NAME");
}

/*===================*/
/* Generic functions */
/*===================*/

char* _ewmh_string_property(uint32_t window, const char *prop)
{
    xcb_connection_t *conn = xcb_connect(NULL, NULL);
    void *val = NULL;
    unsigned int val_len = 0;
    char *ret = NULL;
    xcb_atom_t utf8_string = ewmh_get_atom(conn, "UTF8_STRING");

    xcb_get_property_cookie_t cookie = ewmh_get_property_cookie(
        conn,
        window,
        prop,
        utf8_string
    );

    xcb_get_property_reply_t *reply = xcb_get_property_reply(
        conn, cookie, NULL
    );
    if (reply == NULL) {
        xcb_disconnect(conn);

        return NULL;
    }

    val = xcb_get_property_value(reply);
    if (val != NULL) {
        val_len = xcb_get_property_value_length(reply);
        ret = malloc(val_len + 1);
        memcpy(ret, ((char*)val), (size_t)val_len);
        ret[val_len] = '\0';
    }

    /* Free resources */
    free(reply);
    xcb_disconnect(conn);

    return ret;
}

EWMH_EXTERN_C_END
