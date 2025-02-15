#include <stdio.h>
#include "st0.h"

int main() {
    st0_list_uint32* list_ptr = st0_list_uint32_create(5);
    st0_list_uint32_destroy(list_ptr);

    return 0;
}
