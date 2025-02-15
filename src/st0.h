#ifndef ST0_HEADER
#define ST0_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifdef ST0_INTERNAL
typedef struct {
    uint32_t* data_ptr;
    uint32_t size;
} st0_list_uint32;
#else
typedef void st0_list_uint32;
#endif

st0_list_uint32* st0_list_uint32_create(int size);
void st0_list_uint32_destroy(st0_list_uint32* list_ptr);

#endif
