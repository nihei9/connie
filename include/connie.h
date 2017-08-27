#ifndef connie_CONNIE_H
#define connie_CONNIE_H

#include <stdlib.h>

typedef struct connie_Connie connie_Connie;

typedef void (*connie_TestFunction)(connie_Connie *connie);

connie_Connie *connie_new(const char *caption);
void connie_delete(connie_Connie *connie);
void connie_test(connie_Connie *connie, const char *description, connie_TestFunction f);
void connie_print(const connie_Connie *connie);

void connie_assert_equal_char(connie_Connie *connie, char expected, char actual, int line);
void connie_assert_equal_uchar(connie_Connie *connie, unsigned char expected, unsigned char actual, int line);
void connie_assert_equal_int(connie_Connie *connie, int expected, int actual, int line);
void connie_assert_equal_uint(connie_Connie *connie, unsigned int expected, unsigned int actual, int line);
void connie_assert_equal_long(connie_Connie *connie, long expected, long actual, int line);
void connie_assert_equal_ulong(connie_Connie *connie, unsigned long expected, unsigned long actual, int line);
void connie_assert_null(connie_Connie *connie, const void *actual, int line);
void connie_assert_not_null(connie_Connie *connie, const void *actual, int line);
void connie_assert_equal_string(connie_Connie *connie, const char *expected, const char *actual, int line);

#define connie_NOT_IGNORE_ORDER 0
#define connie_IGNORE_ORDER 1

void connie_assert_equal_char_array(connie_Connie *connie, const char expected[], size_t len, const char actual[], int ignore_order, int line);
void connie_assert_equal_uchar_array(connie_Connie *connie, const unsigned char expected[], size_t len, const unsigned char actual[], int ignore_order, int line);
void connie_assert_equal_int_array(connie_Connie *connie, const int expected[], size_t len, const int actual[], int ignore_order, int line);
void connie_assert_equal_uint_array(connie_Connie *connie, const unsigned int expected[], size_t len, const unsigned int actual[], int ignore_order, int line);
void connie_assert_equal_long_array(connie_Connie *connie, const long expected[], size_t len, const long actual[], int ignore_order, int line);
void connie_assert_equal_ulong_array(connie_Connie *connie, const unsigned long expected[], size_t len, const unsigned long actual[], int ignore_order, int line);

#endif
