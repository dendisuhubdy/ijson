
#include <iostream>
#include "memory.h"


#ifdef DEBUG
    i32 count = 0;
    i32 get_memory_allocated() {
        return count;
    }

    void *_malloc(u32 size) {
        count++;
        void *ptr = malloc(size);
        return ptr;
    }
    void _free(void *ptr) {
        count--;
        free(ptr);
    }


    void * operator new(decltype(sizeof(0)) n) noexcept(false)
    {
        return _malloc(n);
    }
    void operator delete(void *p) throw()
    {
        _free(p);
    }
#endif
