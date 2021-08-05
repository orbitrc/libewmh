/*
//  libewmh/ewmh.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 16. 12:37
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//
*/
#ifndef _EWMH_EWMH_H
#define _EWMH_EWMH_H

#include "base.h"
#include "xcb/collections.h"

EWMH_EXTERN_C_BEGIN

/*=====================================*/
/* Root window properties and messages */
/*=====================================*/

ewmh_uint_list_t ewmh_net_client_list();

uint32_t ewmh_net_number_of_desktops();

void ewmh_set_net_number_of_desktops(uint32_t value);

uint32_t ewmh_net_current_desktop();

void ewmh_set_net_current_desktop(uint32_t value);

uint32_t ewmh_net_active_window();

void ewmh_set_net_active_window(uint32_t window);

/*============================*/
/* Other root window messages */
/*============================*/

/*===============================*/
/* Application window properties */
/*===============================*/

char* ewmh_net_wm_name(uint32_t window);

char* ewmh_net_wm_visible_name(uint32_t window);

char* ewmh_net_wm_icon_name(uint32_t window);

char* ewmh_net_wm_visible_icon_name(uint32_t window);

uint32_t ewmh_net_wm_desktop(uint32_t window);

//ewmh_string_list_t ewmh_net_wm_window_type(uint32_t window);

//ewmh_string_list_t ewmh_net_wm_allowed_actions(uint32_t window);

ewmh_uint_list_t ewmh_net_wm_strut(uint32_t window);

ewmh_uint_list_t ewmh_net_wm_strut_partial(uint32_t window);

ewmh_uint_list_t ewmh_net_wm_icon_geometry(uint32_t window);

//void* ewmh_net_wm_icon(uint32_t window);

uint32_t ewmh_net_wm_pid(uint32_t window);

//void* ewmh_net_wm_handled_icons(uint32_t window);

uint32_t ewmh_net_wm_user_time(uint32_t window);

uint32_t ewmh_net_wm_user_time_window(uint32_t window);

ewmh_uint_list_t ewmh_net_wm_frame_extents(uint32_t window);

//void* ewmh_net_wm_opaque_region(uint32_t window);

uint32_t ewmh_net_wm_bypass_compositor(uint32_t window);

EWMH_EXTERN_C_END

#endif /* _EWMH_EWMH_H */
