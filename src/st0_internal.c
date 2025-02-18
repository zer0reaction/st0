/*
Copyright (c) 2025 Nikita Rudakov (zer0reaction)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define ST0_INTERNAL
#include "st0.h"

/* Praise The Machine Spirit for this macro abomination not to break */

/* exit(1) because we are based */

#define ST0_MACRO_LIST_CREATE_IMPL(typename) \
    typename* list_ptr = malloc(sizeof(*list_ptr)); \
    uint32_t i; \
    \
    list_ptr->size = size; \
    list_ptr->data_ptr = malloc(sizeof(*(list_ptr->data_ptr)) * size); \
    \
    for (i = 0; i < size; i++) { \
        (list_ptr->data_ptr)[i] = 0; \
    } \
    \
    return list_ptr;

#define ST0_MACRO_LIST_SET_VALUE_IMPL(function_name) \
    if (pos >= list_ptr->size) { \
        fprintf(stderr, "Error in %s:\n", function_name); \
        fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, \
                list_ptr->size); \
        exit(1); \
    } \
    \
    (list_ptr->data_ptr)[pos] = val;

#define ST0_MACRO_LIST_GET_VALUE_IMPL(function_name) \
    if (pos >= list_ptr->size) { \
        fprintf(stderr, "Error in %s:\n", function_name); \
        fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, \
                list_ptr->size); \
        exit(1); \
    } \
    \
    return (list_ptr->data_ptr)[pos];

#define ST0_MACRO_LIST_PUSH_BACK_IMPL \
    list_ptr->data_ptr = realloc(list_ptr->data_ptr, \
                                 sizeof(*(list_ptr->data_ptr)) * \
                                 (list_ptr->size + 1)); \
    \
    (list_ptr->data_ptr)[(list_ptr->size)++] = val;

#define ST0_MACRO_LIST_POP_BACK_IMPL(function_name) \
    if (list_ptr->size <= 0) { \
        fprintf(stderr, "Error in %s:\n", function_name); \
        fprintf(stderr, "Invalid size: size = %d.\n", list_ptr->size); \
        exit(1); \
    } \
    \
    return (list_ptr->data_ptr)[--(list_ptr->size)];

#define ST0_MACRO_LIST_PUSH_IMPL(function_name) \
    uint32_t i; \
    \
    if (pos > list_ptr->size) { \
        fprintf(stderr, "Error in %s:\n", function_name); \
        fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, \
                list_ptr->size); \
        exit(1); \
    } \
    \
    list_ptr->data_ptr = realloc(list_ptr->data_ptr, \
                                 sizeof(*(list_ptr->data_ptr)) * \
                                 ++(list_ptr->size)); \
    \
    for (i = list_ptr->size - 1; i > pos; i--) { \
        (list_ptr->data_ptr)[i] = (list_ptr->data_ptr)[i - 1]; \
    } \
    \
    (list_ptr->data_ptr)[pos] = val;

#define ST0_MACRO_LIST_POP_IMPL(function_name, type) \
    uint32_t i; \
    type value; \
    \
    if (pos >= list_ptr->size) { \
        fprintf(stderr, "Error in %s:\n", function_name); \
        fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, \
                list_ptr->size); \
        exit(1); \
    } \
    \
    list_ptr->size--; \
    value = (list_ptr->data_ptr)[pos]; \
    \
    for (i = pos; i < list_ptr->size; i++) { \
        (list_ptr->data_ptr)[i] = (list_ptr->data_ptr)[i + 1]; \
    } \
    \
    return value;

/* general list functions */

void st0_list_destroy(st0_list* list_ptr)
{
    free(list_ptr->data_ptr);
    free(list_ptr);
}

uint32_t st0_list_get_size(st0_list* list_ptr)
{
    return list_ptr->size;
}

/* uint32 list */

st0_list_uint32* st0_list_uint32_create(uint32_t size)
{
    ST0_MACRO_LIST_CREATE_IMPL(st0_list_uint32);
}

void st0_list_uint32_set_value(st0_list_uint32* list_ptr, uint32_t pos,
                               uint32_t val)
{
    ST0_MACRO_LIST_SET_VALUE_IMPL("st0_list_uint32_set_value");
}

uint32_t st0_list_uint32_get_value(st0_list_uint32* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_GET_VALUE_IMPL("st0_list_uint32_get_value");
}

void st0_list_uint32_push_back(st0_list_uint32* list_ptr, uint32_t val)
{
    ST0_MACRO_LIST_PUSH_BACK_IMPL;
}

uint32_t st0_list_uint32_pop_back(st0_list_uint32* list_ptr)
{
    ST0_MACRO_LIST_POP_BACK_IMPL("st0_list_uint32_pop_back");
}

void st0_list_uint32_push(st0_list_uint32* list_ptr, uint32_t pos, uint32_t val)
{
    ST0_MACRO_LIST_PUSH_IMPL("st0_list_uint32_push");
}

uint32_t st0_list_uint32_pop(st0_list_uint32* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_POP_IMPL("st0_list_uint32_pop", uint32_t);
}

/* int32 list */

st0_list_int32* st0_list_int32_create(uint32_t size)
{
    ST0_MACRO_LIST_CREATE_IMPL(st0_list_int32);
}

void st0_list_int32_set_value(st0_list_int32* list_ptr, uint32_t pos,
                              int32_t val)
{
    ST0_MACRO_LIST_SET_VALUE_IMPL("st0_list_int32_set_value");
}

int32_t st0_list_int32_get_value(st0_list_int32* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_GET_VALUE_IMPL("st0_list_int32_get_value");
}

void st0_list_int32_push_back(st0_list_int32* list_ptr, int32_t val)
{
    ST0_MACRO_LIST_PUSH_BACK_IMPL;
}

int32_t st0_list_int32_pop_back(st0_list_int32* list_ptr)
{
    ST0_MACRO_LIST_POP_BACK_IMPL("st0_list_int32_pop_back");
}

void st0_list_int32_push(st0_list_int32* list_ptr, uint32_t pos, int32_t val)
{
    ST0_MACRO_LIST_PUSH_IMPL("st0_list_int32_push");
}

int32_t st0_list_int32_pop(st0_list_int32* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_POP_IMPL("st0_list_int32_pop", int32_t);
}

/* uint64 list */

st0_list_uint64* st0_list_uint64_create(uint32_t size)
{
    ST0_MACRO_LIST_CREATE_IMPL(st0_list_uint64);
}

void st0_list_uint64_set_value(st0_list_uint64* list_ptr, uint32_t pos,
                               uint64_t val)
{
    ST0_MACRO_LIST_SET_VALUE_IMPL("st0_list_uint64_set_value");
}

uint64_t st0_list_uint64_get_value(st0_list_uint64* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_GET_VALUE_IMPL("st0_list_uint64_get_value");
}

void st0_list_uint64_push_back(st0_list_uint64* list_ptr, uint64_t val)
{
    ST0_MACRO_LIST_PUSH_BACK_IMPL;
}

uint64_t st0_list_uint64_pop_back(st0_list_uint64* list_ptr)
{
    ST0_MACRO_LIST_POP_BACK_IMPL("st0_list_uint64_pop_back");
}

void st0_list_uint64_push(st0_list_uint64* list_ptr, uint32_t pos, uint64_t val)
{
    ST0_MACRO_LIST_PUSH_IMPL("st0_list_uint64_push");
}

uint64_t st0_list_uint64_pop(st0_list_uint64* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_POP_IMPL("st0_list_uint64_pop", uint64_t);
}

/* int64 list */

st0_list_int64* st0_list_int64_create(uint32_t size)
{
    ST0_MACRO_LIST_CREATE_IMPL(st0_list_int64);
}

void st0_list_int64_set_value(st0_list_int64* list_ptr, uint32_t pos,
                              int64_t val)
{
    ST0_MACRO_LIST_SET_VALUE_IMPL("st0_list_int64_set_value");
}

int64_t st0_list_int64_get_value(st0_list_int64* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_GET_VALUE_IMPL("st0_list_int64_get_value");
}

void st0_list_int64_push_back(st0_list_int64* list_ptr, int64_t val)
{
    ST0_MACRO_LIST_PUSH_BACK_IMPL;
}

int64_t st0_list_int64_pop_back(st0_list_int64* list_ptr)
{
    ST0_MACRO_LIST_POP_BACK_IMPL("st0_list_int64_pop_back");
}

void st0_list_int64_push(st0_list_int64* list_ptr, uint32_t pos, int64_t val)
{
    ST0_MACRO_LIST_PUSH_IMPL("st0_list_int64_push");
}

int64_t st0_list_int64_pop(st0_list_int64* list_ptr, uint32_t pos)
{
    ST0_MACRO_LIST_POP_IMPL("st0_list_int64_pop", int64_t);
}

/* general string functions */

uint32_t st0_string_get_allocated_bytes(st0_string* string_ptr)
{
    return string_ptr->allocated_bytes;
}

uint32_t st0_string_get_used_bytes(st0_string* string_ptr)
{
    return string_ptr->used_bytes;
}

void st0_string_destroy(st0_string* string_ptr)
{
    free(string_ptr->data_ptr);
    free(string_ptr);
}

/* utf8 string functions */

st0_string_utf8* st0_string_utf8_create(uint32_t allocated_bytes)
{
    uint32_t i;
    st0_string_utf8* string_ptr = malloc(sizeof(*string_ptr));

    string_ptr->allocated_bytes = allocated_bytes;
    string_ptr->data_ptr = malloc(sizeof(*(string_ptr->data_ptr)) *
                                  allocated_bytes);
    string_ptr->used_bytes = 0;

    for (i = 0; i < allocated_bytes; i++) {
        (string_ptr->data_ptr)[i] = 0;
    }

    return string_ptr;
}

void st0_string_utf8_assign_to_literal(st0_string_utf8* string_ptr,
                                       const char* literal_ptr)
{
    uint32_t i;
    uint32_t literal_bytes = 0;
    while (literal_ptr[literal_bytes++] != '\0');

    if (literal_bytes > string_ptr->allocated_bytes) {
        fprintf(stderr, "Error in %s:\n", "st0_string_utf8_assign_to_literal");
        fprintf(stderr, "Invalid literal size (including null char): string \
                         size = %d, literal size = %d.\n",
                         string_ptr->allocated_bytes, literal_bytes);
        exit(1);
    }

    for (i = 0; i < string_ptr->allocated_bytes; i++) {
        (string_ptr->data_ptr)[i] = 0;
    }

    for (i = 0; i < literal_bytes; i++) {
        (string_ptr->data_ptr)[i] = literal_ptr[i];
    }

    string_ptr->used_bytes = literal_bytes;
}
