#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define da_reserve(da, additional)\
    do {\
        if (((da)->count + additional) > (da)->capacity) {\
            if ((da)->capacity == 0) {\
                (da)->capacity = 1;\
            }\
            while (((da)->count + additional) > (da)->capacity) {\
                (da)->capacity *= 2;\
            }\
            (da)->data = realloc((da)->data, (da)->capacity * sizeof(*(da)->data));\
        }\
    } while (0)

#define da_insert(da, index, value)\
    do {\
        da_reserve((da), 1);\
        memmove((da)->data + (index) + 1, (da)->data + (index),\
        ((da)->count++ - (index)) * sizeof(*(da)->data));\
        (da)->data[index] = (value);\
    } while (0)

#define da_remove(da, index)\
    do {\
        memmove((da)->data + (index), (da)->data + (index) + 1,\
        ((da)->count-- - (index)) * sizeof(*(da)->data));\
    } while (0)

#define da_push(da, value)\
    do {\
        da_reserve((da), 1);\
        (da)->data[(da)->count++] = (value);\
    } while (0)

#define da_append_raw(da, other, other_count)\
    do {\
        da_reserve((da), (other_count));\
        memcpy((da)->data + (da)->count, (other), (other_count) * sizeof(*(da)->data));\
        (da)->count += (other_count);\
    } while (0)

#define da_append(da, other) da_append_raw((da), (other)->data, (other)->count)

#define da_at(da, i) (da)->data[assert((da)->count > i), i]
#define da_first(da) (da)->data[assert((da)->count > 0), 0]
#define da_last(da) (da)->data[assert((da)->count > 0), (da)->count - 1]
#define da_pop(da) (da)->data[assert((da)->count > 0), --(da)->count]
#define da_foreach(x, da) for (typeof((da)->data[0]) *x = (da)->data; x < (da)->data + (da)->count; x++)
