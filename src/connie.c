#include "connie.h"
#include "records.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

struct connie_Connie {
	const char *caption;

	struct {
		size_t max_description_len;
	} print_info;

	connie_Records *recs;
	jmp_buf jmp;
};


connie_Connie *connie_new(const char *caption)
{
	connie_Connie *connie;
	connie_Records *recs;
	char *cap = NULL;

	connie = (connie_Connie *) malloc(sizeof(connie_Connie));
	if (connie == NULL) {
		return NULL;
	}

	if (caption != NULL) {
		cap = strdup(caption);
	}

	recs = connie_new_records();
	if (recs == NULL) {
		free(connie);
		return NULL;
	}

	connie->caption = (const char *) cap;
	connie->print_info.max_description_len = 0;
	connie->recs = recs;

	return connie;
}


void connie_delete(connie_Connie *connie)
{
	if (connie == NULL) {
		return;
	}

	free((void *) connie->caption);
	connie->caption = NULL;

	connie_delete_records(&connie->recs);

	free(connie);
}


void connie_test(connie_Connie *connie, const char *description, connie_TestFunction f)
{
	int ret;
	char *des = NULL;
	size_t description_len;

	if (connie == NULL || description == NULL || f == NULL) {
		return;
	}

	description_len = strlen(description);
	if (description_len <= 0) {
		return;
	}

	if (description_len > connie->print_info.max_description_len) {
		connie->print_info.max_description_len = description_len;
	}

	connie_entry_record(connie->recs, description);

	ret = setjmp(connie->jmp);
	if (ret == 0) {
		(*f)(connie);
	}
}


void connie_print(const connie_Connie *connie)
{
	connie_Record *rec;

	if (connie == NULL) {
		return;
	}

	printf("# ");
	if (connie->caption != NULL) {
		printf("%s\n", connie->caption);
	}
	else {
		printf("test\n");
	}
	printf("----------------------------------------------------------------\n");

	while ((rec = connie_next_record(connie->recs)) != NULL) {
		const connie_AssertionEntry *a_entry;
		const char *description = connie_get_description(rec);
		size_t description_len = strlen(description);
		int at_line_1;

		at_line_1 = 1;
		while ((a_entry = connie_next_assertion(connie->recs, rec)) != NULL) {
			const char *assertion = connie_get_assertion_string(a_entry->ac);
			const char *result = NULL;
			int iresult = connie_get_result(a_entry->ac);

			if (at_line_1) {
				int i;

				printf("%s", description);
				for (i = description_len; i < connie->print_info.max_description_len; i++) {
					printf(" ");
				}
				at_line_1 = 0;
			}
			else {
				int i;

				for (i = 0; i < connie->print_info.max_description_len; i++) {
					printf(" ");

				}
			}
			printf(" | ");

			if (iresult == connie_OK_AC) {
				result = "OK";

				printf("\x1b[39m");
			}
			else if (iresult == connie_NG_AC) {
				result = "NG";

				printf("\x1b[33m");
			}
			printf("%d: %s ... %s\n", a_entry->line, assertion, result);
			printf("\x1b[39m");
		}
	}
}


void connie_assert_equal_char(connie_Connie *connie, char expected, char actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_CHAR_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_CHAR_OK, line);
}


void connie_assert_equal_uchar(connie_Connie *connie, unsigned char expected, unsigned char actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_UCHAR_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_UCHAR_OK, line);
}


void connie_assert_equal_int(connie_Connie *connie, int expected, int actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_INT_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_INT_OK, line);
}


void connie_assert_equal_uint(connie_Connie *connie, unsigned int expected, unsigned int actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_UINT_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_UINT_OK, line);
}


void connie_assert_equal_long(connie_Connie *connie, long expected, long actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_LONG_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_LONG_OK, line);
}


void connie_assert_equal_ulong(connie_Connie *connie, unsigned long expected, unsigned long actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != expected) {
		connie_record(connie->recs, connie_AC_EQUAL_ULONG_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_ULONG_OK, line);
}


void connie_assert_null(connie_Connie *connie, const void *actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual != NULL) {
		connie_record(connie->recs, connie_AC_NULL_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_NULL_OK, line);
}


void connie_assert_not_null(connie_Connie *connie, const void *actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (actual == NULL) {
		connie_record(connie->recs, connie_AC_NOT_NULL_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_NOT_NULL_OK, line);
}


void connie_assert_equal_string(connie_Connie *connie, const char *expected, const char *actual, int line)
{
	if (connie == NULL) {
		return;
	}

	if (strcmp(actual, expected) != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_STRING_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_STRING_OK, line);
}


static int connie_assert_equal_array(connie_Connie *connie, const char *chexpected, size_t len, const char *actual, connie_Type elem_type, int ignore_order, int line);


void connie_assert_equal_char_array(connie_Connie *connie, const char expected[], size_t len, const char actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_CHAR, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_CHAR_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_CHAR_ARRAY_OK, line);
}


void connie_assert_equal_uchar_array(connie_Connie *connie, const unsigned char expected[], size_t len, const unsigned char actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_UCHAR, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_UCHAR_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_UCHAR_ARRAY_OK, line);
}


void connie_assert_equal_int_array(connie_Connie *connie, const int expected[], size_t len, const int actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_INT, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_INT_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_INT_ARRAY_OK, line);
}


void connie_assert_equal_uint_array(connie_Connie *connie, const unsigned int expected[], size_t len, const unsigned int actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_UINT, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_UINT_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_UINT_ARRAY_OK, line);
}


void connie_assert_equal_long_array(connie_Connie *connie, const long expected[], size_t len, const long actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_LONG, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_LONG_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_LONG_ARRAY_OK, line);
}


void connie_assert_equal_ulong_array(connie_Connie *connie, const unsigned long expected[], size_t len, const unsigned long actual[], int ignore_order, int line)
{
	int ret;
	
	ret = connie_assert_equal_array(connie, (const char *) expected, len, (const char *) actual, connie_TYPE_ULONG, ignore_order, line);
	if (ret != 0) {
		connie_record(connie->recs, connie_AC_EQUAL_ULONG_ARRAY_NG, line);
		longjmp(connie->jmp, 1);
	}

	connie_record(connie->recs, connie_AC_EQUAL_ULONG_ARRAY_OK, line);
}


static int connie_assert_equal_array(connie_Connie *connie, const char *expected, size_t len, const char *actual, connie_Type elem_type, int ignore_order, int line)
{
	const connie_Comparator comp = comparator[elem_type];
	const size_t elem_size = type_size[elem_type];

	if (ignore_order == connie_NOT_IGNORE_ORDER) {
		size_t i;

		for (i = 0; i < len; i++) {
			if (comp(&actual[i * elem_size], &expected[i * elem_size]) != 0) {
				return 1;
			}
		}
	}
	else {
		size_t i, j;
		char *expected_marks;

		expected_marks = (char *) calloc(len, sizeof (char));
		for (i = 0; i < len; i++) {
			expected_marks[i] = 0;
		}

		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				if (expected_marks[j] != 0) {
					continue;
				}

				if (comp(&actual[i * elem_size], &expected[j * elem_size]) == 0) {
					expected_marks[j] = 1;
					continue;
				}
			}
		}
		
		for (i = 0; i < len; i++) {
			if (expected_marks[i] == 0) {
				free(expected_marks);
				return 1;
			}
		}

		free(expected_marks);
	}

	return 0;
}