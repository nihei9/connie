#ifndef connie_CONNIE_SUGAR_H
#define connie_CONNIE_SUGAR_H

#include "connie.h"

#define A_EQL_CHAR(connie, expected, actual) connie_assert_equal_char(connie, expected, actual, __LINE__)
#define A_EQL_UCHAR(connie, expected, actual) connie_assert_equal_uchar(connie, expected, actual, __LINE__)
#define A_EQL_INT(connie, expected, actual) connie_assert_equal_int(connie, expected, actual, __LINE__)
#define A_EQL_UINT(connie, expected, actual) connie_assert_equal_uint(connie, expected, actual, __LINE__)
#define A_EQL_LONG(connie, expected, actual) connie_assert_equal_long(connie, expected, actual, __LINE__)
#define A_EQL_ULONG(connie, expected, actual) connie_assert_equal_ulong(connie, expected, actual, __LINE__)
#define A_NULL(connie, actual) connie_assert_null(connie, actual, __LINE__)
#define A_NOT_NULL(connie, actual) connie_assert_not_null(connie, actual, __LINE__)
#define A_EQL_STRING(connie, expected, actual) connie_assert_equal_string(connie, expected, actual, __LINE__)

#define A_EQL_CHAR_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_char_array(connie, expected, len, actual, ignore_order, __LINE__)
#define A_EQL_UCHAR_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_uchar_array(connie, expected, len, actual, ignore_order, __LINE__)
#define A_EQL_INT_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_int_array(connie, expected, len, actual, ignore_order, __LINE__)
#define A_EQL_UINT_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_uint_array(connie, expected, len, actual, ignore_order, __LINE__)
#define A_EQL_LONG_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_long_array(connie, expected, len, actual, ignore_order, __LINE__)
#define A_EQL_ULONG_ARRAY(connie, expected, len, actual, ignore_order) connie_assert_equal_ulong_array(connie, expected, len, actual, ignore_order, __LINE__)

#define TEST(connie, func) connie_test(connie, #func, func)

#endif
