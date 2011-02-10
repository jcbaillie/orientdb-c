#include "o_record_cache.h"
#include "o_memory.h"
#include "o_map.h"

struct o_record_cache
{
	struct o_map * map;
	int cache_size;
};

unsigned int o_record_id_hash(void *par, int size)
{
	struct o_record_id * rid = (struct o_record_id *) par;
	return (o_record_id_cluster_id(rid) + o_record_id_record_id(rid)) % size;
}

void o_entry_record_create(void ** key, void ** value)
{
	o_record_refer((struct o_record *) *value);
}

void o_entry_record_free(void ** key, void ** value)
{
	o_record_release((struct o_record *) *value);
}

int o_key_record_compare(void * key1, void * key2)
{
	struct o_record_id * rec1 = (struct o_record_id *) key1;
	struct o_record_id * rec2 = (struct o_record_id *) key2;
	int dif = o_record_id_cluster_id(rec1) - o_record_id_cluster_id(rec2);
	if (dif != 0)
		return dif;
	return o_record_id_record_id(rec1) - o_record_id_record_id(rec2);
}

struct o_record_cache * o_record_cache_new()
{
	struct o_record_cache * cache = o_malloc(sizeof(struct o_record_cache));
	cache->map = o_map_new(o_record_id_hash, o_entry_record_create, o_entry_record_free,o_key_record_compare);
	return cache;
}

void o_record_cache_put(struct o_record_cache * cache, struct o_record * record)
{
	o_map_put(cache->map, o_record_get_id(record), record);
	if (o_map_size(cache->map) > cache->cache_size)
		o_map_remove(cache->map, o_map_first_key(cache->map));
}

void o_record_cache_remove(struct o_record_cache * cache, struct o_record * record)
{
	o_map_remove(cache->map, o_record_get_id(record));
}

void o_record_cache_clear(struct o_record_cache * cache)
{
	o_map_clear(cache->map);
}

struct o_record * o_record_cache_get(struct o_record_cache * cache, struct o_record_id *id)
{
	return (struct o_record *) o_map_get(cache->map, id);
}
