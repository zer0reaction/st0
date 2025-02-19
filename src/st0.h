/*
Copyright (c) 2025 Nikita Rudakov (zer0reaction)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef ST0_HEADER
#define ST0_HEADER

#include <stdint.h>

#ifdef ST0_INTERNAL

typedef unsigned char char8_t;
typedef float float32_t;
typedef double float64_t;

typedef enum {
    ST0_TYPE_LIST_UINT32,
    ST0_TYPE_LIST_INT32,
    ST0_TYPE_LIST_UINT64,
    ST0_TYPE_LIST_INT64,
    ST0_TYPE_LIST_FLOAT32,
    ST0_TYPE_LIST_FLOAT64,
    ST0_TYPES_COUNT
} st0_type;

typedef struct {
    st0_type type;
    void* data_ptr;
    uint32_t size;
} st0_list;

#else

typedef void st0_list;

#endif

void     st0_list_destroy(st0_list* list_ptr);
uint32_t st0_list_get_size(st0_list* list_ptr);
void     st0_list_set_value(st0_list* list_ptr, uint32_t pos, void* value_ptr);
void     st0_list_get_value(st0_list* list_ptr, void* buffer_ptr, uint32_t pos);
void     st0_list_push_back(st0_list* list_ptr, void* value_ptr);
void     st0_list_pop_back(st0_list* list_ptr, void* buffer_ptr);
void     st0_list_push(st0_list* list_ptr, uint32_t pos, void* value_ptr);
void     st0_list_pop(st0_list* list_ptr, void* buffer_ptr, uint32_t pos);

st0_list* st0_list_uint32_create(uint32_t size);
st0_list* st0_list_int32_create(uint32_t size);
st0_list* st0_list_uint64_create(uint32_t size);
st0_list* st0_list_int64_create(uint32_t size);
st0_list* st0_list_float32_create(uint32_t size);
st0_list* st0_list_float64_create(uint32_t size);

#endif
