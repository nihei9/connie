#include <stdlib.h>
#include "assertion_code.h"


const char *connie_get_assertion_string(connie_AssertionCode ac)
{
	const char *s = NULL;
	
	switch (ac) {
	case connie_AC_EQUAL_CHAR_OK:
	case connie_AC_EQUAL_CHAR_NG:
		s = "EQUAL CHAR";
		break;
	case connie_AC_EQUAL_UCHAR_OK:
	case connie_AC_EQUAL_UCHAR_NG:
		s = "EQUAL UCHAR";
		break;
	case connie_AC_EQUAL_INT_OK:
	case connie_AC_EQUAL_INT_NG:
		s = "EQUAL INT";
		break;
	case connie_AC_EQUAL_UINT_OK:
	case connie_AC_EQUAL_UINT_NG:
		s = "EQUAL UINT";
			break;
	case connie_AC_EQUAL_LONG_OK:
	case connie_AC_EQUAL_LONG_NG:
		s = "EQUAL LONG";
		break;
	case connie_AC_EQUAL_ULONG_OK:
	case connie_AC_EQUAL_ULONG_NG:
		s = "EQUAL ULONG";
		break;
	case connie_AC_NULL_OK:
	case connie_AC_NULL_NG:
		s = "NULL";
		break;
	case connie_AC_NOT_NULL_OK:
	case connie_AC_NOT_NULL_NG:
		s = "NOT NULL";
		break;
	case connie_AC_EQUAL_STRING_OK:
	case connie_AC_EQUAL_STRING_NG:
		s = "EQUAL STRING";
		break;
	case connie_AC_EQUAL_CHAR_ARRAY_OK:
	case connie_AC_EQUAL_CHAR_ARRAY_NG:
		s = "EQUAL CHAR ARRAY";
		break;
	case connie_AC_EQUAL_UCHAR_ARRAY_OK:
	case connie_AC_EQUAL_UCHAR_ARRAY_NG:
		s = "EQUAL UCHAR ARRAY";
		break;
	case connie_AC_EQUAL_INT_ARRAY_OK:
	case connie_AC_EQUAL_INT_ARRAY_NG:
		s = "EQUAL INT ARRAY";
		break;
	case connie_AC_EQUAL_UINT_ARRAY_OK:
	case connie_AC_EQUAL_UINT_ARRAY_NG:
		s = "EQUAL UINT ARRAY";
		break;
	case connie_AC_EQUAL_LONG_ARRAY_OK:
	case connie_AC_EQUAL_LONG_ARRAY_NG:
		s = "EQUAL LONG ARRAY";
		break;
	case connie_AC_EQUAL_ULONG_ARRAY_OK:
	case connie_AC_EQUAL_ULONG_ARRAY_NG:
		s = "EQUAL ULONG ARRAY";
		break;
	}

	return s;
}


int connie_get_result(connie_AssertionCode ac)
{
	if (ac > _connie_AC_OK_GROUP_START && ac < _connie_AC_OK_GROUP_END) {
		return connie_OK_AC;
	}
	else if (ac > _connie_AC_NG_GROUP_START && ac < _connie_AC_NG_GROUP_END) {
		return connie_NG_AC;
	}

	return connie_INVALID_AC;
}

