/*
//  collections.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 15. 22:54
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//
*/
#ifndef _EWMH_XCB_COLLECTIONS_H
#define _EWMH_XCB_COLLECTIONS_H

#include <xcb/xcb.h>

#include "../base.h"

EWMH_EXTERN_C_BEGIN

typedef struct ewmh_atom_list_t {
    size_t length;
    size_t capacity;
    xcb_atom_t *atoms;
} ewmh_atom_list_t;

/*==========================*/
/* ewmh_atom_list_t methods */
/*==========================*/

ewmh_atom_list_t ewmh_atom_list_new();
void ewmh_atom_list_free(ewmh_atom_list_t *list);

EWMH_EXTERN_C_END

#endif /* _EWMH_XCB_COLLECTIONS_H */
