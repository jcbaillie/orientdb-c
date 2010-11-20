#include "o_output_stream_socket.h"
#include "o_output_stream_internal.h"
#include "o_database_socket.h"
#include "o_memory.h"

struct o_output_stream_socket
{
	struct o_output_stream stream;
	struct o_database_socket * socket;
};

void o_output_stream_socket_write_bytes(struct o_output_stream * stream, void *bytes, int nbytes)
{
	struct o_output_stream_socket * str = (struct o_output_stream_socket *) stream;
	o_database_socket_send(str->socket, bytes, nbytes);
}

void o_output_stream_socket_write(struct o_output_stream * stream, char c)
{
	o_output_stream_socket_write_bytes(stream, &c, 1);
}

void o_output_stream_socket_flush(struct o_output_stream * stream)
{
}

void o_output_stream_socket_free(struct o_output_stream * stream)
{
	o_free(stream);
}

struct o_output_stream * o_output_stream_socket_new(struct o_database_socket * socket)
{
	struct o_output_stream_socket * new_str = o_malloc(sizeof(struct o_output_stream_socket));
	new_str->socket = socket;
	new_str->stream.o_output_stream_write_bytes = o_output_stream_socket_write_bytes;
	new_str->stream.o_output_stream_write = o_output_stream_socket_write;
	new_str->stream.o_output_stream_flush = o_output_stream_socket_flush;
	new_str->stream.o_output_stream_free = o_output_stream_socket_free;
	return (struct o_output_stream *) new_str;
}
