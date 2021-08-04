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

/*========*/
/* Errors */
/*========*/
#define EWMH_SUCCESS                0
#define EWMH_ERROR_OUT_OF_RANGE     1

typedef struct ewmh_atom_list_t {
    size_t length;
    size_t capacity;
    xcb_atom_t *atoms;
} ewmh_atom_list_t;

#define EWMH_UINT_LIST_MULTIPLE     4

typedef struct ewmh_uint_list_t {
    size_t length;
    size_t capacity;
    uint32_t *uints;
} ewmh_uint_list_t;

/*==========================*/
/* ewmh_atom_list_t methods */
/*==========================*/

ewmh_atom_list_t ewmh_atom_list_new();
void ewmh_atom_list_free(ewmh_atom_list_t *list);

/*==============================*/
/* ewmh_uint_list_t methods */
/*==============================*/

ewmh_uint_list_t ewmh_uint_list_new();
void ewmh_uint_list_push(ewmh_uint_list_t *list, uint32_t uint);
size_t ewmh_uint_list_length(ewmh_uint_list_t *list);
uint32_t ewmh_uint_list_at(ewmh_uint_list_t *list, size_t index, int *error);
void ewmh_uint_list_free(ewmh_uint_list_t *list);

EWMH_EXTERN_C_END

#endif /* _EWMH_XCB_COLLECTIONS_H */
