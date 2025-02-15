#include <stdio.h>
#include "st0.h"

int main() {
    st0_list_uint32* list_ptr = st0_list_uint32_create(0);
    
    st0_list_uint32_set(list_ptr, 0, 69);
    printf("%d\n", st0_list_uint32_get(list_ptr, 0));
    
    st0_list_uint32_destroy(list_ptr);
    return 0;
}
