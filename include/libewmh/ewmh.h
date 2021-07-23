/*
//  libewmh/ewmh.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 16. 12:37
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//
*/
#ifndef _LIBEWMH_EWMH_H
#define _LIBEWMH_EWMH_H

#include "base.h"
#include "xcb/collections.h"

EWMH_EXTERN_C_BEGIN

/*====================================*/
/* Root window properties and messages*/
/*====================================*/

ewmh_uint_list_t ewmh_net_client_list();

uint32_t ewmh_net_number_of_desktops();

void ewmh_set_net_number_of_desktops(uint32_t value);

uint32_t ewmh_net_current_desktop();

void ewmh_set_net_current_desktop(uint32_t value);

uint32_t ewmh_net_active_window();

EWMH_EXTERN_C_END

#endif /* _LIBEWMH_EWMH_H */
