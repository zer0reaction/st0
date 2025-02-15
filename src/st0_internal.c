#define ST0_INTERNAL
#include "st0.h"

st0_list_uint32* st0_list_uint32_create(uint32_t size) {
    st0_list_uint32* list_ptr = malloc(sizeof(*list_ptr));
    int i;

    list_ptr->size = size;
    list_ptr->data_ptr = malloc(sizeof(*(list_ptr->data_ptr)) * size);


    for (i = 0; i < size; i++) {
        (list_ptr->data_ptr)[i] = 0;
    }

    return list_ptr;
}

void st0_list_uint32_destroy(st0_list_uint32* list_ptr) {
    free(list_ptr->data_ptr);
    free(list_ptr);
}

void st0_list_uint32_set(st0_list_uint32* list_ptr, uint32_t pos, uint32_t val) {
    if (pos >= list_ptr->size) {
        fprintf(stderr, "Error in st0_list_uint32_set: invalid pos.\n");
        fprintf(stderr, "    pos = %d, size = %d.\n", pos, list_ptr->size);
        exit(1);
    }

    (list_ptr->data_ptr)[pos] = val;
}

uint32_t st0_list_uint32_get(st0_list_uint32* list_ptr, uint32_t pos) {
    if (pos >= list_ptr->size) {
        fprintf(stderr, "Error in st0_list_uint32_get: invalid pos.\n");
        fprintf(stderr, "    pos = %d, size = %d.\n", pos, list_ptr->size);
        exit(1);
    }

    return (list_ptr->data_ptr)[pos];
}

void st0_list_uint32_append(st0_list_uint32* list_ptr, uint32_t val) {
    list_ptr->data_ptr = realloc(list_ptr->data_ptr, sizeof(*(list_ptr->data_ptr)) * (list_ptr->size + 1));
    (list_ptr->data_ptr)[list_ptr->size] = val;
    list_ptr->size++;
}
