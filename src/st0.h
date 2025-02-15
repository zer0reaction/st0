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

st0_list_uint32* st0_list_uint32_create(uint32_t size);
void st0_list_uint32_destroy(st0_list_uint32* list_ptr);
void st0_list_uint32_set(st0_list_uint32* list_ptr, uint32_t pos, uint32_t val);
uint32_t st0_list_uint32_get(st0_list_uint32* list_ptr, uint32_t pos);
void st0_list_uint32_append(st0_list_uint32* list_ptr, uint32_t val);

#endif
