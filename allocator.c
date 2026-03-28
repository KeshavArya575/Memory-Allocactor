#include "allocator.h"

unsigned char heap[HEAP_SIZE];
size_t offset = 0;

void* my_malloc(size_t size) {

    
    size_t curr = 0;

    while(curr < offset) {

        Block *block = (Block*) &heap[curr];

        if(block->free && block->size >= size) {
            block->free = 0;
            return (void*)(block + 1);
        }

        curr += sizeof(Block) + block->size;
    }

    
    if(offset + sizeof(Block) + size > HEAP_SIZE) {
        return NULL;
    }

    Block *block = (Block*) &heap[offset];

    block->size = size;
    block->free = 0;

    void *ptr = (void*)(block + 1);

    offset += sizeof(Block) + size;

    return ptr;
}

void my_free(void *ptr) {

    Block *block = (Block*)ptr - 1;
    block->free = 1;
}

