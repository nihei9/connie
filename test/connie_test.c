#include <stdio.h>
#include "connie.h"
#include "connie_sugar.h"

void test_assert_equal_int_OK(connie_Connie *c);
void test_assert_equal_int_NG(connie_Connie *c);
void test_assert_equal_uint_OK(connie_Connie *c);
void test_assert_equal_uint_NG(connie_Connie *c);
void test_assert_null_OK(connie_Connie *c);
void test_assert_null_NG(connie_Connie *c);
void test_assert_not_null_OK(connie_Connie *c);
void test_assert_not_null_NG(connie_Connie *c);
void test_assert_equal_string_OK(connie_Connie *c);
void test_assert_equal_string_NG(connie_Connie *c);
void test_assert_equal_char_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_char_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_char_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_char_array_ignore_order_NG(connie_Connie *c);
void test_assert_equal_uchar_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_uchar_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_uchar_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_uchar_array_ignore_order_NG(connie_Connie *c);
void test_assert_equal_int_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_int_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_int_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_int_array_ignore_order_NG(connie_Connie *c);
void test_assert_equal_uint_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_uint_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_uint_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_uint_array_ignore_order_NG(connie_Connie *c);
void test_assert_equal_long_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_long_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_long_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_long_array_ignore_order_NG(connie_Connie *c);
void test_assert_equal_ulong_array_not_ignore_order_OK(connie_Connie *c);
void test_assert_equal_ulong_array_not_ignore_order_NG(connie_Connie *c);
void test_assert_equal_ulong_array_ignore_order_OK(connie_Connie *c);
void test_assert_equal_ulong_array_ignore_order_NG(connie_Connie *c);
void test_multi_assertion_1(connie_Connie *c);
void test_multi_assertion_2(connie_Connie *c);

int main(void)
{
	connie_Connie *c;

	c = connie_new(__FILE__);

	TEST(c, test_assert_equal_int_OK);
	TEST(c, test_assert_equal_int_NG);
	TEST(c, test_assert_equal_uint_OK);
	TEST(c, test_assert_equal_uint_NG);
	TEST(c, test_assert_null_OK);
	TEST(c, test_assert_null_NG);
	TEST(c, test_assert_not_null_OK);
	TEST(c, test_assert_not_null_NG);
	TEST(c, test_assert_equal_string_OK);
	TEST(c, test_assert_equal_string_NG);
	TEST(c, test_assert_equal_char_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_char_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_char_array_ignore_order_OK);
	TEST(c, test_assert_equal_char_array_ignore_order_NG);
	TEST(c, test_assert_equal_uchar_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_uchar_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_uchar_array_ignore_order_OK);
	TEST(c, test_assert_equal_uchar_array_ignore_order_NG);
	TEST(c, test_assert_equal_int_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_int_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_int_array_ignore_order_OK);
	TEST(c, test_assert_equal_int_array_ignore_order_NG);
	TEST(c, test_assert_equal_uint_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_uint_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_uint_array_ignore_order_OK);
	TEST(c, test_assert_equal_uint_array_ignore_order_NG);
	TEST(c, test_assert_equal_long_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_long_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_long_array_ignore_order_OK);
	TEST(c, test_assert_equal_long_array_ignore_order_NG);
	TEST(c, test_assert_equal_ulong_array_not_ignore_order_OK);
	TEST(c, test_assert_equal_ulong_array_not_ignore_order_NG);
	TEST(c, test_assert_equal_ulong_array_ignore_order_OK);
	TEST(c, test_assert_equal_ulong_array_ignore_order_NG);
	TEST(c, test_multi_assertion_1);
	TEST(c, test_multi_assertion_2);

	connie_print(c);

	connie_delete(c);

	return 0;
}

void test_assert_equal_int_OK(connie_Connie *c)
{
	A_EQL_INT(c, 1, 1);
}

void test_assert_equal_int_NG(connie_Connie *c)
{
	A_EQL_INT(c, 1, 2);
}

void test_assert_equal_uint_OK(connie_Connie *c)
{
	A_EQL_UINT(c, 1, 1);
}

void test_assert_equal_uint_NG(connie_Connie *c)
{
	A_EQL_UINT(c, 1, 2);
}

void test_assert_null_OK(connie_Connie *c)
{
	A_NULL(c, NULL);
}

void test_assert_null_NG(connie_Connie *c)
{
	A_NULL(c, "connie");
}

void test_assert_not_null_OK(connie_Connie *c)
{
	A_NOT_NULL(c, "connie");
}

void test_assert_not_null_NG(connie_Connie *c)
{
	A_NOT_NULL(c, NULL);
}

void test_assert_equal_string_OK(connie_Connie *c)
{
	A_EQL_STRING(c, "connie", "connie");
}

void test_assert_equal_string_NG(connie_Connie *c)
{
	A_EQL_STRING(c, "connie", "xxxxxx");
}

void test_assert_equal_char_array_not_ignore_order_OK(connie_Connie *c)
{
	const char expected[] = {2, 3, 5, 7, 11};
	const char actual[] = {2, 3, 5, 7, 11};

	A_EQL_CHAR_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_char_array_not_ignore_order_NG(connie_Connie *c)
{
	const char expected[] = {2, 3, 5, 7, 11};
	const char actual[] = {2, 3, 5, 11, 7};

	A_EQL_CHAR_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_char_array_ignore_order_OK(connie_Connie *c)
{
	const char expected[] = {2, 3, 5, 7, 11};
	const char actual[] = {11, 3, 2, 5, 7};

	A_EQL_CHAR_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_char_array_ignore_order_NG(connie_Connie *c)
{
	const char expected[] = {2, 3, 5, 7, 11};
	const char actual[] = {11, 3, 2, 9, 7};

	A_EQL_CHAR_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_uchar_array_not_ignore_order_OK(connie_Connie *c)
{
	const unsigned char expected[] = {2, 3, 5, 7, 11};
	const unsigned char actual[] = {2, 3, 5, 7, 11};

	A_EQL_UCHAR_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_uchar_array_not_ignore_order_NG(connie_Connie *c)
{
	const unsigned char expected[] = {2, 3, 5, 7, 11};
	const unsigned char actual[] = {2, 3, 5, 11, 7};

	A_EQL_UCHAR_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_uchar_array_ignore_order_OK(connie_Connie *c)
{
	const unsigned char expected[] = {2, 3, 5, 7, 11};
	const unsigned char actual[] = {11, 3, 2, 5, 7};

	A_EQL_UCHAR_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_uchar_array_ignore_order_NG(connie_Connie *c)
{
	const unsigned char expected[] = {2, 3, 5, 7, 11};
	const unsigned char actual[] = {11, 3, 2, 9, 7};

	A_EQL_UCHAR_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_int_array_not_ignore_order_OK(connie_Connie *c)
{
	const int expected[] = {2, 3, 5, 7, 11};
	const int actual[] = {2, 3, 5, 7, 11};

	A_EQL_INT_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_int_array_not_ignore_order_NG(connie_Connie *c)
{
	const int expected[] = {2, 3, 5, 7, 11};
	const int actual[] = {2, 3, 5, 11, 7};

	A_EQL_INT_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_int_array_ignore_order_OK(connie_Connie *c)
{
	const int expected[] = {2, 3, 5, 7, 11};
	const int actual[] = {11, 3, 2, 5, 7};

	A_EQL_INT_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_int_array_ignore_order_NG(connie_Connie *c)
{
	const int expected[] = {2, 3, 5, 7, 11};
	const int actual[] = {11, 3, 2, 9, 7};

	A_EQL_INT_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_uint_array_not_ignore_order_OK(connie_Connie *c)
{
	const unsigned int expected[] = {2, 3, 5, 7, 11};
	const unsigned int actual[] = {2, 3, 5, 7, 11};

	A_EQL_UINT_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_uint_array_not_ignore_order_NG(connie_Connie *c)
{
	const unsigned int expected[] = {2, 3, 5, 7, 11};
	const unsigned int actual[] = {2, 3, 5, 11, 7};

	A_EQL_UINT_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_uint_array_ignore_order_OK(connie_Connie *c)
{
	const unsigned int expected[] = {2, 3, 5, 7, 11};
	const unsigned int actual[] = {11, 3, 2, 5, 7};

	A_EQL_UINT_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_uint_array_ignore_order_NG(connie_Connie *c)
{
	const unsigned int expected[] = {2, 3, 5, 7, 11};
	const unsigned int actual[] = {11, 3, 2, 9, 7};

	A_EQL_INT_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_long_array_not_ignore_order_OK(connie_Connie *c)
{
	const long expected[] = {2, 3, 5, 7, 11};
	const long actual[] = {2, 3, 5, 7, 11};

	A_EQL_LONG_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_long_array_not_ignore_order_NG(connie_Connie *c)
{
	const long expected[] = {2, 3, 5, 7, 11};
	const long actual[] = {2, 3, 5, 11, 7};

	A_EQL_LONG_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_long_array_ignore_order_OK(connie_Connie *c)
{
	const long expected[] = {2, 3, 5, 7, 11};
	const long actual[] = {11, 3, 2, 5, 7};

	A_EQL_LONG_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_long_array_ignore_order_NG(connie_Connie *c)
{
	const long expected[] = {2, 3, 5, 7, 11};
	const long actual[] = {11, 3, 2, 9, 7};

	A_EQL_LONG_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_ulong_array_not_ignore_order_OK(connie_Connie *c)
{
	const unsigned long expected[] = {2, 3, 5, 7, 11};
	const unsigned long actual[] = {2, 3, 5, 7, 11};

	A_EQL_ULONG_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_ulong_array_not_ignore_order_NG(connie_Connie *c)
{
	const unsigned long expected[] = {2, 3, 5, 7, 11};
	const unsigned long actual[] = {2, 3, 5, 11, 7};

	A_EQL_ULONG_ARRAY(c, expected, 5, actual, connie_NOT_IGNORE_ORDER);
}

void test_assert_equal_ulong_array_ignore_order_OK(connie_Connie *c)
{
	const unsigned long expected[] = {2, 3, 5, 7, 11};
	const unsigned long actual[] = {11, 3, 2, 5, 7};

	A_EQL_ULONG_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_assert_equal_ulong_array_ignore_order_NG(connie_Connie *c)
{
	const unsigned long expected[] = {2, 3, 5, 7, 11};
	const unsigned long actual[] = {11, 3, 2, 9, 7};

	A_EQL_ULONG_ARRAY(c, expected, 5, actual, connie_IGNORE_ORDER);
}

void test_multi_assertion_1(connie_Connie *c)
{
	A_EQL_INT(c, -1, -1);
	A_EQL_UINT(c, 1, 1);
	A_NULL(c, NULL);
	A_NOT_NULL(c, "connie");
}

void test_multi_assertion_2(connie_Connie *c)
{
	A_EQL_INT(c, -1, -1);
	A_EQL_UINT(c, 1, 1);
	A_NULL(c, "connie");
	A_NOT_NULL(c, "connie");
}
