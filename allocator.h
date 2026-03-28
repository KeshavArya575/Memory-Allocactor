#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

#define HEAP_SIZE 1024

typedef struct {
    size_t size;
    int free;
} Block;

void* my_malloc(size_t size);
void  my_free(void *ptr);

#endif