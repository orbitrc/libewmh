/*
//  xcb.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 15. 22:52
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  xcb helper functions.
*/
#ifndef _EWMH_XCB_XCB_H
#define _EWMH_XCB_XCB_H

#include <xcb/xcb.h>

#include "../base.h"
#include "collections.h"

xcb_atom_t ewmh_get_atom(xcb_connection_t *conn, const char *atom);

xcb_get_property_cookie_t ewmh_get_property_cookie(xcb_connection_t *conn,
        xcb_window_t w, const char *prop, xcb_atom_t type);

void ewmh_change_property(xcb_connection_t *conn, uint8_t mode, xcb_window_t w,
        const char *prop, xcb_atom_t type, size_t data_len, void *data);

void ewmh_send_client_message_event(xcb_connection_t *conn, xcb_window_t w,
        xcb_client_message_event_t *event);

#endif /* _EWMH_XCB_XCB_H */
