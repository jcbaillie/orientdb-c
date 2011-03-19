#include "o_record_factory.h"
#include "o_record.h"
#include "o_record_raw.h"
#include "o_document.h"
#include "o_exceptions.h"
#include <stdio.h>

struct o_record * o_record_factory(char record_type)
{
	switch (record_type)
	{
	case RAW_RECORD_TYPE:
		return o_record_raw_new();
	case DOCUMENT_RECORD_TYPE:
		return o_document_o_record(o_document_new());
	}
	char message[80];
	sprintf(message, "Unsupported record type:%i", record_type);
	throw(o_exception_new(message,20));
	//Never executed only remove warning.
	return 0;
}

struct o_record * o_record_factory_id(char record_type, struct o_record_id * id)
{
	switch (record_type)
	{
	case RAW_RECORD_TYPE:
		return o_record_raw_new_id(id);
	case DOCUMENT_RECORD_TYPE:
		return o_document_o_record(o_document_new_id(id));
	}
	char message[80];
	sprintf(message, "Unsupported record type:%i", record_type);
	throw(o_exception_new(message,20));
	//Never executed only remove warning.
	return 0;
}
