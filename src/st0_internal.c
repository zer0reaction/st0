/*
Copyright (c) 2025 Nikita Rudakov (zer0reaction)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define ST0_INTERNAL
#define ST0_DEBUG

#include "st0.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef ST0_DEBUG
#include <assert.h>
#endif

void st0_list_destroy(st0_list* list_ptr) {
    free((list_ptr->data_ptr));
    free(list_ptr);
}

uint32_t st0_list_get_size(st0_list* list_ptr) {
    return list_ptr->size;
}

void st0_list_set_value(st0_list* list_ptr, uint32_t pos, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        ((uint32_t*)(list_ptr->data_ptr))[pos] = *((uint32_t*)value_ptr);
    }
}

void st0_list_get_value(st0_list* list_ptr, void* buffer_ptr, uint32_t pos) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        *((uint32_t*)buffer_ptr) = ((uint32_t*)(list_ptr->data_ptr))[pos];
    }
}

void st0_list_push_back(st0_list* list_ptr, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        list_ptr->data_ptr = realloc(list_ptr->data_ptr,
                                     sizeof(uint32_t) * ++(list_ptr->size));
        ((uint32_t*)(list_ptr->data_ptr))[list_ptr->size - 1] =
            *((uint32_t*)value_ptr);
    }
}

void st0_list_pop_back(st0_list* list_ptr, void* buffer_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        if (buffer_ptr != NULL) {
            *((uint32_t*)buffer_ptr) =
                ((uint32_t*)(list_ptr->data_ptr))[--(list_ptr->size)];
        } else {
            list_ptr->size--;
        }
    }
}

void st0_list_push(st0_list* list_ptr, uint32_t pos, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        uint32_t i;

        list_ptr->data_ptr = realloc(list_ptr->data_ptr,
                                     sizeof(uint32_t) * ++(list_ptr->size));

        for (i = list_ptr->size - 1; i > pos; i--) {
            ((uint32_t*)(list_ptr->data_ptr))[i] =
                ((uint32_t*)(list_ptr->data_ptr))[i - 1];
        }

        ((uint32_t*)(list_ptr->data_ptr))[pos] = *((uint32_t*)value_ptr);
    }
}

void st0_list_pop(st0_list* list_ptr, void* buffer_ptr, uint32_t pos) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 1);
    #endif

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        uint32_t i;

        if (buffer_ptr != NULL) {
            *((uint32_t*)buffer_ptr) = ((uint32_t*)(list_ptr->data_ptr))[pos];
        }

        list_ptr->size--;
        for (i = pos; i < list_ptr->size; i++) {
            ((uint32_t*)(list_ptr->data_ptr))[i] =
                ((uint32_t*)(list_ptr->data_ptr))[i + 1];
        }
    }
}

st0_list* st0_list_uint32_create(uint32_t size) {
    uint32_t i;
    st0_list* list_ptr = malloc(sizeof(st0_list));

    list_ptr->type = ST0_TYPE_LIST_UINT32;
    list_ptr->size = size;
    list_ptr->data_ptr = malloc(sizeof(uint32_t) * size);

    for (i = 0; i < list_ptr->size; i++) {
        ((uint32_t*)(list_ptr->data_ptr))[i] = 0;
    }

    return list_ptr;
}
