#ifndef connie_ASSERTION_CODE_H
#define connie_ASSERTION_CODE_H

typedef enum connie_AssertionCode {
	// Group of OK codes
	_connie_AC_OK_GROUP_START,

	connie_AC_EQUAL_CHAR_OK,
	connie_AC_EQUAL_UCHAR_OK,
	connie_AC_EQUAL_INT_OK,
	connie_AC_EQUAL_UINT_OK,
	connie_AC_EQUAL_LONG_OK,
	connie_AC_EQUAL_ULONG_OK,
	connie_AC_NULL_OK,
	connie_AC_NOT_NULL_OK,
	connie_AC_EQUAL_STRING_OK,
	connie_AC_EQUAL_CHAR_ARRAY_OK,
	connie_AC_EQUAL_UCHAR_ARRAY_OK,
	connie_AC_EQUAL_INT_ARRAY_OK,
	connie_AC_EQUAL_UINT_ARRAY_OK,
	connie_AC_EQUAL_LONG_ARRAY_OK,
	connie_AC_EQUAL_ULONG_ARRAY_OK,
	
	_connie_AC_OK_GROUP_END,

	// Group of NG codes
	_connie_AC_NG_GROUP_START,
	
	connie_AC_EQUAL_CHAR_NG,
	connie_AC_EQUAL_UCHAR_NG,
	connie_AC_EQUAL_INT_NG,
	connie_AC_EQUAL_UINT_NG,
	connie_AC_EQUAL_LONG_NG,
	connie_AC_EQUAL_ULONG_NG,
	connie_AC_NULL_NG,
	connie_AC_NOT_NULL_NG,
	connie_AC_EQUAL_STRING_NG,
	connie_AC_EQUAL_CHAR_ARRAY_NG,
	connie_AC_EQUAL_UCHAR_ARRAY_NG,
	connie_AC_EQUAL_INT_ARRAY_NG,
	connie_AC_EQUAL_UINT_ARRAY_NG,
	connie_AC_EQUAL_LONG_ARRAY_NG,
	connie_AC_EQUAL_ULONG_ARRAY_NG,

	_connie_AC_NG_GROUP_END,
} connie_AssertionCode;


#define connie_OK_AC 0
#define connie_NG_AC 1
#define connie_INVALID_AC 2

const char *connie_get_assertion_string(connie_AssertionCode ac);
int connie_get_result(connie_AssertionCode ac);

#endif
