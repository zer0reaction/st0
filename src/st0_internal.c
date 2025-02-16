/*
Copyright (c) 2025 Nikita Rudakov (zer0reaction)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define ST0_INTERNAL
#include "st0.h"

/* Praise The Machine Spirit for this macro abomination not to break */

#define ST0_MACRO_LIST_CREATE_IMPL(type, typename) \
typename* list_ptr = malloc(sizeof(*list_ptr)); \
int i; \
list_ptr->size = size; \
list_ptr->data_ptr = malloc(sizeof(*(list_ptr->data_ptr)) * size); \
for (i = 0; i < size; i++) { \
    (list_ptr->data_ptr)[i] = 0; \
} \
return list_ptr;

#define ST0_MACRO_LIST_DESTROY_IMPL \
free(list_ptr->data_ptr); \
free(list_ptr);

#define ST0_MACRO_LIST_SET_IMPL(function_name) \
if (pos >= list_ptr->size) { \
    fprintf(stderr, "Error in %s:\n", function_name); \
    fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, list_ptr->size); \
    exit(1); \
} \
(list_ptr->data_ptr)[pos] = val;

#define ST0_MACRO_LIST_GET_IMPL(function_name) \
if (pos >= list_ptr->size) { \
    fprintf(stderr, "Error in %s:\n", function_name); \
    fprintf(stderr, "Invalid pos value: pos = %d, size = %d.\n", pos, list_ptr->size); \
    exit(1); \
} \
return (list_ptr->data_ptr)[pos];

#define ST0_MACRO_LIST_APPEND_IMPL \
list_ptr->data_ptr = realloc(list_ptr->data_ptr, sizeof(*(list_ptr->data_ptr)) * (list_ptr->size + 1)); \
(list_ptr->data_ptr)[list_ptr->size] = val; \
list_ptr->size++;

/* uint32 list */

st0_list_uint32* st0_list_uint32_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE_IMPL(uint32_t, st0_list_uint32);
}

void st0_list_uint32_destroy(st0_list_uint32* list_ptr) {
    ST0_MACRO_LIST_DESTROY_IMPL;
}

void st0_list_uint32_set(st0_list_uint32* list_ptr, uint32_t pos, uint32_t val) {
    ST0_MACRO_LIST_SET_IMPL("st0_list_uint32_set");
}

uint32_t st0_list_uint32_get(st0_list_uint32* list_ptr, uint32_t pos) {
    ST0_MACRO_LIST_GET_IMPL("st0_list_uint32_get");
}

void st0_list_uint32_push_back(st0_list_uint32* list_ptr, uint32_t val) {
    ST0_MACRO_LIST_APPEND_IMPL;
}

/* int32 list */

st0_list_int32* st0_list_int32_create(uint32_t size) {
    ST0_MACRO_LIST_CREATE_IMPL(int32_t, st0_list_int32);
}

void st0_list_int32_destroy(st0_list_int32* list_ptr) {
    ST0_MACRO_LIST_DESTROY_IMPL;
}

void st0_list_int32_set(st0_list_int32* list_ptr, uint32_t pos, int32_t val) {
    ST0_MACRO_LIST_SET_IMPL("st0_list_int32_set");
}

int32_t st0_list_int32_get(st0_list_int32* list_ptr, uint32_t pos) {
    ST0_MACRO_LIST_GET_IMPL("st0_list_int32_get");
}

void st0_list_int32_push_back(st0_list_int32* list_ptr, int32_t val) {
    ST0_MACRO_LIST_APPEND_IMPL;
}
