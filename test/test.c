#include "suites.h"

TEST_INITIALIZE
{
	ADD_SUITE(o_exceptions_suite, "exceptions management tests");
	ADD_SUITE(o_map_suite, "o_map tests");
	ADD_SUITE(o_connection_remote_suite, "remote connection tests");
	ADD_SUITE(o_url_resolve_suite, "url parsing tests");
	ADD_SUITE(o_string_buffer_suite, "string buffer tests");
	ADD_SUITE(o_document_value_suite, "document value tests");
	ADD_SUITE(o_record_suite, "simple record tests");
	ADD_SUITE(o_string_printer_suite, "printer test");
	ADD_SUITE(o_document_suite, "document tests");
	ADD_SUITE(o_input_stream_suite, "input stream test");
	ADD_SUITE(o_native_lock_suite, "basic native lock test suite");
	ADD_SUITE(o_database_suite, "test on base database");
	ADD_SUITE(o_database_document_suite, "test on base database");
	ADD_SUITE(o_database_document_metadata_suite, "test database metadata load");
	ADD_SUITE(o_list_suite, "test list management");
	ADD_SUITE(o_list_record_suite, "test record list management");
	ADD_SUITE(o_database_query_suite, "test execute query on database");
	ADD_SUITE(o_database_document_query_suite, "test execute query on document database");
	ADD_SUITE(o_pool_suite, "a suite of test on pool");
	ADD_SUITE(o_output_stream_suite, "a suite of test on output stream");
}

