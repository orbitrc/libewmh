#include <libewmh/xcb/collections.h>

#include <stdlib.h>

EWMH_EXTERN_C_BEGIN

ewmh_uint_list_t ewmh_uint_list_new()
{
    ewmh_uint_list_t list;
    list.length = 0;
    list.capacity = EWMH_UINT_LIST_MULTIPLE;
    list.uints = (uint32_t*)malloc(sizeof(uint32_t) * list.capacity);

    return list;
}

void ewmh_uint_list_push(ewmh_uint_list_t *list, uint32_t uint)
{
    /* Grow capacity. */
    if (list->length == list->capacity) {
        uint32_t *new_uints = (uint32_t*)malloc(sizeof(uint32_t) *
            (list->capacity + EWMH_UINT_LIST_MULTIPLE));
        list->capacity += EWMH_UINT_LIST_MULTIPLE;
        for (size_t i = 0; i < list->capacity; ++i) {
            new_uints[i] = list->uints[i];
        }
        free(list->uints);
        list->uints = new_uints;
    }

    /* Append value. */
    list->uints[list->length] = uint;
    list->length += 1;
}

size_t ewmh_uint_list_length(ewmh_uint_list_t *list)
{
    return list->length;
}

uint32_t ewmh_uint_list_at(ewmh_uint_list_t *list, size_t index, int *error)
{
    /* Bounding check. */
    if (index >= list->length) {
        if (error != NULL) {
            *error = EWMH_ERROR_OUT_OF_RANGE;
        }
        return 0;
    }

    if (error != NULL) {
        *error = EWMH_SUCCESS;
    }
    return list->uints[index];
}

void ewmh_uint_list_free(ewmh_uint_list_t *list)
{
    free(list->uints);
    list->uints = NULL;
    list->capacity = 0;
    list->length = 0;
}

EWMH_EXTERN_C_END

