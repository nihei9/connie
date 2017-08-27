#include "type.h"

static int compare_char(const void *v1, const void *v2);
static int compare_uchar(const void *v1, const void *v2);
static int compare_int(const void *v1, const void *v2);
static int compare_uint(const void *v1, const void *v2);
static int compare_long(const void *v1, const void *v2);
static int compare_ulong(const void *v1, const void *v2);

const connie_Comparator comparator[] = {
    compare_char,
    compare_uchar,
    compare_int,
    compare_uint,
    compare_long,
    compare_ulong,
};

const size_t type_size[] = {
    sizeof (char),
    sizeof (unsigned char),
    sizeof (int),
    sizeof (unsigned int),
    sizeof (long),
    sizeof (unsigned long),
};

static int compare_char(const void *value1, const void *value2)
{
    char v1 = *((char *) value1);
    char v2 = *((char *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}

static int compare_uchar(const void *value1, const void *value2)
{
    unsigned char v1 = *((unsigned char *) value1);
    unsigned char v2 = *((unsigned char *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}

static int compare_int(const void *value1, const void *value2)
{
    int v1 = *((int *) value1);
    int v2 = *((int *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}

static int compare_uint(const void *value1, const void *value2)
{
    unsigned int v1 = *((unsigned int *) value1);
    unsigned int v2 = *((unsigned int *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}

static int compare_long(const void *value1, const void *value2)
{
    long v1 = *((long *) value1);
    long v2 = *((long *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}

static int compare_ulong(const void *value1, const void *value2)
{
    unsigned long v1 = *((unsigned long *) value1);
    unsigned long v2 = *((unsigned long *) value2);

    if (v1 > v2) {
        return -1;
    }
    if (v1 < v2) {
        return 1;
    }

    return 0;
}