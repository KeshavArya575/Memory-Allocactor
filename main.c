#include <stdio.h>
#include "allocator.h"


int main() {

    int *a = my_malloc(4);
    int *b = my_malloc(4);

    *a = 10;
    *b = 20;

    my_free(a);

    int *c = my_malloc(4);

    *c = 99;

    printf("b: %d\n", *b);
    printf("c: %d\n", *c);

    printf("a: %p\n", a);
    printf("c: %p\n", c);

    return 0;
}