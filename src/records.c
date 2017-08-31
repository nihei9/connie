#include <stdlib.h>
#include <string.h>
#include "records.h"

#include <stdio.h>


struct connie_Record {
	const char *description;

	struct {
		/*
		 * connie_AssertionEntry配列の実体はconnie_Recordsが保持する。
		 * この配列は伸長時にメモリ領域が移動する可能性があるため、ポインタではなくインデックスで管理する。
		 */
		int head_index; // Index of array of connie_AssertionEntry
		int len;
	} a_entries; // Assertion etntries

	struct {
		int ptr;
	} iter;

	connie_Record *next;
};


static connie_Record *connie_new_record(const char *description, int a_entries_head_index)
{
	connie_Record *rec;
	char *des = NULL;

	rec = malloc(sizeof (connie_Record));
	if (rec == NULL) {
		return NULL;
	}

	if (description != NULL) {
		des = strdup(description);
	}

	rec->description = des;

	rec->a_entries.head_index = a_entries_head_index;
	rec->a_entries.len = 0;

	rec->iter.ptr = 0;

	rec->next = NULL;

	return rec;
}


static void connie_delete_record(connie_Record **rec)
{
	connie_Record *_rec;

	if (rec == NULL) {
		return;
	}

	_rec = *rec;

	free((void *) _rec->description);
	_rec->description = NULL;
	_rec->next = NULL;
	free(_rec);
	*rec = NULL;
}


#define connie_INIT_A_ENTRIES_SIZE 128
#define connie_A_ENTRIES_STEP_SIZE 128


struct connie_Records {
	connie_Record *head;
	connie_Record *last;

	struct {
		connie_AssertionEntry *arr;
		size_t size;
		int fill_index;
	} a_entries;

	struct {
		connie_Record *ptr;
		connie_AssertionEntry a_entry;
	} iter;
};


connie_Records *connie_new_records(void)
{
	connie_Records *recs;
	connie_AssertionEntry *a_entries;

	recs = (connie_Records *) malloc(sizeof (connie_Records));
	if (recs == NULL) {
		return NULL;
	}

	a_entries = (connie_AssertionEntry *) calloc(connie_INIT_A_ENTRIES_SIZE, sizeof (connie_AssertionEntry));
	if (a_entries == NULL) {
		free(recs);
		return NULL;
	}

	recs->head = NULL;
	recs->last = NULL;

	recs->a_entries.arr = a_entries;
	recs->a_entries.size = connie_INIT_A_ENTRIES_SIZE;
	recs->a_entries.fill_index = 0;

	recs->iter.ptr = NULL;

	return recs;
}


void connie_delete_records(connie_Records **recs)
{
	connie_Records *_recs;
	connie_Record *rec;

	if (recs == NULL) {
		return;
	}

	_recs = *recs;

	rec = _recs->head;
	while (rec != NULL) {
		connie_Record *next = rec->next;

		connie_delete_record(&rec);
		rec = next;
	}
	_recs->head = NULL;
	_recs->last = NULL;

	free(_recs->a_entries.arr);
	_recs->a_entries.arr = NULL;

	_recs->iter.ptr = NULL;

	free(_recs);
	*recs = NULL;
}


void connie_entry_record(connie_Records *recs, const char *description)
{
	connie_Record *new_rec;

	new_rec = connie_new_record(description, recs->a_entries.fill_index);
	if (new_rec == NULL) {
		return;
	}

	if (recs->head == NULL) {
		recs->head = new_rec;
		recs->last = new_rec;

		recs->iter.ptr = new_rec;
	}
	else {
		recs->last->next = new_rec;
		recs->last = new_rec;
	}
}


void connie_record(connie_Records *recs, connie_AssertionCode ac, int line)
{
	connie_Record *rec;
	connie_AssertionEntry *a_ent;

	if (recs->a_entries.fill_index >= recs->a_entries.size) {
		connie_AssertionEntry *new_a_entries;
		size_t new_size;

		new_size = recs->a_entries.size + connie_A_ENTRIES_STEP_SIZE;
		new_a_entries = (connie_AssertionEntry *) realloc(recs->a_entries.arr, sizeof (connie_AssertionEntry) * new_size);
		if (new_a_entries == NULL) {
			return;
		}

		recs->a_entries.arr = new_a_entries;
		recs->a_entries.size = new_size;
	}
	a_ent = &recs->a_entries.arr[recs->a_entries.fill_index++];

	a_ent->line = line;
	a_ent->ac = ac;

	rec = recs->last;
	rec->a_entries.len++;
}


connie_Record *connie_next_record(connie_Records *recs)
{
	connie_Record *rec;

	if (recs->iter.ptr == NULL) {
		return NULL;
	}

	rec = recs->iter.ptr;
	recs->iter.ptr = rec->next;

	return rec;
}


const char *connie_get_description(connie_Record *rec)
{
	return rec->description;
}


const connie_AssertionEntry *connie_next_assertion(connie_Records *recs, connie_Record *rec)
{
	connie_AssertionEntry a_entry;
	int a_entry_offset;

	if (rec->iter.ptr >= rec->a_entries.len) {
		return NULL;
	}

	a_entry_offset = rec->a_entries.head_index + rec->iter.ptr;
	recs->iter.a_entry = recs->a_entries.arr[a_entry_offset];

	rec->iter.ptr++;

	return &recs->iter.a_entry;
}
