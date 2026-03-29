# Memory Allocator

A heap allocator implemented from scratch in C.

## How it works
- Fixed 1024-byte heap backed by a static array
- Each allocation prefixed with a Block header (size + free flag)
- `my_malloc` - first-fit scan of free list, falls back to bump allocation
- `my_free` - O(1) flag flip

## What it demonstrates
- Pointer arithmetic (`block + 1` to step past header)
- Free list traversal
- Use-after-free behavior (a and c point to same address after realloc)
- Heap fragmentation (no coalescing — intentional, shows the limitation)

## Known limitations (by design)
- No block splitting or coalescing
- No alignment guarantees
- Not thread-safe
- 1024 byte heap only

## Build
- gcc allocator.c main.c -o allocator
- ./allocator.exe
