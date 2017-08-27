/*
 * connie_Records *recs = connie_new_records();
 *
 * connie_entry_record(recs, "description");
 *
 * connie_record(recs, ac, __LINE__);
 *
 * connie_delete_records(&recs);
 */

#ifndef connie_RECORDS_H
#define connie_RECORDS_H

#include "assertion_code.h"

typedef struct connie_Records connie_Records;
typedef struct connie_Record connie_Record;

typedef struct connie_AssertionEntry {
	int line;
	connie_AssertionCode ac;
} connie_AssertionEntry;

connie_Records *connie_new_records(void);
void connie_delete_records(connie_Records **recs);
void connie_entry_record(connie_Records *recs, const char *description);
void connie_record(connie_Records *recs, connie_AssertionCode ac, int line);
connie_Record *connie_next_record(connie_Records *recs);
const char *connie_get_description(connie_Record *rec);
const connie_AssertionEntry *connie_next_assertion(connie_Records *recs, connie_Record *rec);

#endif
