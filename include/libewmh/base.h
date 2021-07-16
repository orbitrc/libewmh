/*
//  base.h
//
//  Author:     Yujeonja
//  Created:    2021. 07. 15. 22:47
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Base macros, constants and functions.
*/
#ifndef _EWMH_BASE_H
#define _EWMH_BASE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
    #define EWMH_EXTERN_C_BEGIN extern "C" {
#else
    #define EWMH_EXTERN_C_BEGIN
#endif

#ifdef __cplusplus
    #define EWMH_EXTERN_C_END }
#else
    #define EWMH_EXTERN_C_END
#endif

#endif /* _EWMH_BASE_H */
