#define ST0_INTERNAL
#include "st0.h"

st0_list_uint32* st0_list_uint32_create(int size) {
    st0_list_uint32* list_ptr = (st0_list_uint32*)malloc(sizeof(*list_ptr));
    
    list_ptr->size = size;
    list_ptr->data_ptr = (uint32_t*)malloc(sizeof(*(list_ptr->data_ptr)) * size);
    
    return list_ptr;
}

void st0_list_uint32_destroy(st0_list_uint32* list_ptr) {
    if (list_ptr != NULL) {
        free(list_ptr->data_ptr);
        free(list_ptr);
    }
}
