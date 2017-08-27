#ifndef connie_TYPE_H
#define connie_TYPE_H

#include <stdlib.h>

typedef enum connie_Type {
    connie_TYPE_CHAR,
    connie_TYPE_UCHAR,
    connie_TYPE_INT,
    connie_TYPE_UINT,
    connie_TYPE_LONG,
    connie_TYPE_ULONG,
} connie_Type;

typedef int (*connie_Comparator)(const void *v1, const void *v2);

extern const connie_Comparator comparator[];
extern const size_t type_size[];

#endif
