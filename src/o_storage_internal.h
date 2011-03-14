#ifndef O_STORAGE_INTERNAL_H_
#define O_STORAGE_INTERNAL_H_
#include "o_storage.h"
#include "o_storage_configuration.h"

struct o_storage
{
	char * name;
	char * user;
	int ref_count;
	query_result_callback callback;
	void * callback_addinfo;
	struct o_storage_configuration * configuration;
	long long (*o_storage_create_record)(struct o_storage * storage, int cluster, struct o_raw_buffer * content);
	struct o_query_engine * (*o_storage_get_query_engine)(struct o_storage * storage);
	struct o_raw_buffer * (*o_storage_read_record)(struct o_storage * storage, struct o_record_id * id);
	int (*o_storage_update_record)(struct o_storage * storage, struct o_record_id * id, struct o_raw_buffer * content);
	int (*o_storage_delete_record)(struct o_storage * storage, struct o_record_id * id, int version);
	char ** (*o_storage_get_cluster_names)(struct o_storage * storage, int * names_count);
	int (*o_storage_get_cluster_id_by_name)(struct o_storage * storage, char * name);
	int (*o_storage_get_default_cluster_id)(struct o_storage * storage);
	void (*o_storage_commit_transaction)(struct o_storage *storage, struct o_transaction * transaction);
	void (*o_storage_final_release)(struct o_storage * storage);
	struct o_raw_buffer * (*o_storage_get_metadata)(struct o_storage * storage);
	void (*o_storage_close)(struct o_storage * storage);
	void (*o_storage_free)(struct o_storage * storage);
};

/*! \brief Initialize the storage with the base data.
 *
 * \param storage to init.
 * \parma name of storage.
 */
void o_storage_internal_new(struct o_storage *storage, char * name, char *username);

/*! \brief Retrieve the name of storage.
 *
 * \param storage where retrieve the name.
 */
char * o_storage_get_name(struct o_storage *storage);

/*! \brief Retrieve the user of storage.
 *
 * \param storage where retrieve the user.
 */
char * o_storage_get_user(struct o_storage *storage);

/*! \brief Dealloc the storage internal memory.
 *
 *\param storage to free.
 */
void o_storage_internal_free(struct o_storage *storage);

/*! \brief Retrieve the configuration of storage.
 *
 * \param storage to retrieve configuration.
 * \return the storage configuration.
 */
struct o_storage_configuration * o_storage_get_configuration(struct o_storage *storage);

#endif /* O_STORAGE_INTERNAL_H_ */
