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

/* list functions */

#define ST0_MACRO_LIST_CREATE(type_name, type_enum) \
    uint32_t i; \
    st0_list* list_ptr = malloc(sizeof(st0_list)); \
    \
    list_ptr->type = type_enum; \
    list_ptr->size = size; \
    list_ptr->data_ptr = malloc(sizeof(type_name) * size); \
    \
    for (i = 0; i < size; i++) { \
        ((type_name*)(list_ptr->data_ptr))[i] = 0; \
    } \
    \
    return list_ptr;

void st0_list_destroy(st0_list* list_ptr) {
    free((list_ptr->data_ptr));
    free(list_ptr);
}

uint32_t st0_list_get_size(st0_list* list_ptr) {
    return list_ptr->size;
}

void st0_list_set_value(st0_list* list_ptr, uint32_t pos, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        ((type_name*)(list_ptr->data_ptr))[pos] = *((type_name*)value_ptr);

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

void st0_list_get_value(st0_list* list_ptr, void* buffer_ptr, uint32_t pos) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        *((type_name*)buffer_ptr) = ((type_name*)(list_ptr->data_ptr))[pos];

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

void st0_list_push_back(st0_list* list_ptr, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        list_ptr->data_ptr = realloc(list_ptr->data_ptr, \
                                     sizeof(type_name) * ++(list_ptr->size)); \
        ((type_name*)(list_ptr->data_ptr))[list_ptr->size - 1] = \
            *((type_name*)value_ptr);

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

void st0_list_pop_back(st0_list* list_ptr, void* buffer_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        if (buffer_ptr != NULL) { \
            *((type_name*)buffer_ptr) = \
                ((type_name*)(list_ptr->data_ptr))[--(list_ptr->size)]; \
        } else { \
            list_ptr->size--; \
        }

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

void st0_list_push(st0_list* list_ptr, uint32_t pos, void* value_ptr) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        uint32_t i; \
        \
        list_ptr->data_ptr = realloc(list_ptr->data_ptr, \
                                     sizeof(type_name) * ++(list_ptr->size)); \
        \
        for (i = list_ptr->size - 1; i > pos; i--) { \
            ((type_name*)(list_ptr->data_ptr))[i] = \
                ((type_name*)(list_ptr->data_ptr))[i - 1]; \
        } \
        \
        ((type_name*)(list_ptr->data_ptr))[pos] = *((type_name*)value_ptr);

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

void st0_list_pop(st0_list* list_ptr, void* buffer_ptr, uint32_t pos) {
    #ifdef ST0_DEBUG
    assert(ST0_TYPES_COUNT == 6);
    #endif

    #define IMPL(type_name) \
        uint32_t i; \
        \
        if (buffer_ptr != NULL) { \
            *((type_name*)buffer_ptr) = \
                ((type_name*)(list_ptr->data_ptr))[pos]; \
        } \
        \
        list_ptr->size--; \
        for (i = pos; i < list_ptr->size; i++) { \
            ((type_name*)(list_ptr->data_ptr))[i] = \
                ((type_name*)(list_ptr->data_ptr))[i + 1]; \
        }

    if (list_ptr->type == ST0_TYPE_LIST_UINT32) {
        IMPL(uint32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT32) {
        IMPL(int32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_UINT64) {
        IMPL(uint64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_INT64) {
        IMPL(int64_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT32) {
        IMPL(float32_t);
    } else if (list_ptr->type == ST0_TYPE_LIST_FLOAT64) {
        IMPL(float64_t);
    }

    #undef IMPL
}

st0_list* st0_list_uint32_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(uint32_t, ST0_TYPE_LIST_UINT32);
}

st0_list* st0_list_int32_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(int32_t, ST0_TYPE_LIST_INT32);
}

st0_list* st0_list_uint64_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(uint64_t, ST0_TYPE_LIST_UINT64);
}

st0_list* st0_list_int64_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(int64_t, ST0_TYPE_LIST_INT64);
}

st0_list* st0_list_float32_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(float32_t, ST0_TYPE_LIST_FLOAT32);
}

st0_list* st0_list_float64_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE(float64_t, ST0_TYPE_LIST_FLOAT64);
}

/* end of list functions */

/* string functions */

void st0_string_destroy(st0_string* string_ptr) {
    free(string_ptr->data_ptr);
    free(string_ptr);
}

st0_string* st0_string_utf8_create(uint32_t size) {
    uint32_t i;
    st0_string* string_ptr = malloc(sizeof(st0_string));

    string_ptr->type = ST0_TYPE_STRING_UTF8;
    string_ptr->data_ptr = malloc(sizeof(char8_t) * size);
    string_ptr->size = size;

    for (i = 0; i < size; i++) {
        ((char8_t*)(string_ptr->data_ptr))[i] = 0;
    }

    return string_ptr;
}

/* end of string functions */
