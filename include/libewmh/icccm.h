/*
//  libewmh/icccm.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 16. 00:16
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//
*/
#ifndef _EWMH_ICCCM_H
#define _EWMH_ICCCM_H

#include <xcb/xcb.h>

#include "base.h"

EWMH_EXTERN_C_BEGIN

char* icccm_wm_client_machine(xcb_window_t w);

EWMH_EXTERN_C_END

#endif /* _EWMH_ICCCM_H */
