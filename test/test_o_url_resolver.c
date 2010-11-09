#include "test_o_url_resolver.h"
#include "../src/o_url_resolver.h"
#include "../src/o_memory.h"
#include <string.h>
#include <TestFramework/test.h>
#include <stdio.h>
#define TEST_URL "remote:127.0.0.1:2424/dbname"

void o_url_resolve_type_test()
{
	enum o_url_type type = o_url_resolve_type(TEST_URL);
	assert_true(type == REMOTE, "Wrong url Type");
}

void o_url_resolve_information_test()
{
	char *path;
	char *database;
	enum o_url_type type;
	o_url_resolve_information(TEST_URL, &type, &path, &database);
	assert_true(type == REMOTE, "Wrong url Type");
	assert_true(strcmp(path, "127.0.0.1:2424") == 0, "Wrong path ");
	assert_true(strcmp(database, "dbname") == 0, "Wrong database name");
	o_free(path);
	o_free(database);
}

void o_url_resolve_host_port_from_path_test()
{
	char *host;
	int port;
	int ret = o_url_resolve_host_port_from_path("127.0.0.1:2424", &host, &port);
	assert_true(ret == 0, "wrong return value");
	assert_true(strcmp(host, "127.0.0.1") == 0, "wrong host name");
	assert_true(port == 2424, "wrong port");
	o_free(host);
}

void o_url_resolve_host_from_path_test()
{
	char *host;
	int port;
	int ret = o_url_resolve_host_port_from_path("127.0.0.1", &host, &port);
	printf("%i",ret);
	assert_true(ret == 1, "wrong return value");
	assert_true(strcmp(host, "127.0.0.1") == 0, "wrong host name");
	o_free(host);
}

void o_url_resolve_suite()
{
	ADD_TEST(o_url_resolve_type_test, "Test a resolve of type from url");
	ADD_TEST(o_url_resolve_information_test, "Test a url resolver information");
	ADD_TEST(o_url_resolve_host_port_from_path_test, "Test a host and port resolve from path");
	ADD_TEST(o_url_resolve_host_from_path_test, "Test an only host resolve from path");
}