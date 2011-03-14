#ifndef O_STORAGE_H_
#define O_STORAGE_H_
#include "o_raw_buffer.h"
#include "o_database_error_handler.h"
#include "o_record_id.h"
#include "o_transaction.h"
#include "o_query_engine.h"
#include "o_query_callback.h"

#define CLUSTER_INTERNAL_NAME "internal"
#define CLUSTER_INDEX_NAME "index"
#define CLUSTER_DEFAULT_NAME "default"
#define DATA_DEFAULT_NAME "default"

struct o_storage;

/**
 * Create a new record to the storage.
 *
 * @param storage where create the record.
 * @param cluster where put the record.
 * @param the record content.
 * @return the new identifier of created record.
 */
long long o_storage_create_record(struct o_storage * storage, int cluster, struct o_raw_buffer * content);

/*! \brief Retrieve A query engine for current browser.
 *
 * \param storage where retrieve the query engine.
 * \return the query engine instance.
 */
struct o_query_engine * o_storage_get_query_engine(struct o_storage * storage);

/**
 * Read a record from the storage
 *
 * @param storage the storage where read.
 * @param id the identifier of record to read.
 * @param version poiter to int filled with te version fo current readed record.
 * @return the content of read record
 *
 */
struct o_raw_buffer * o_storage_read_record(struct o_storage * storage, struct o_record_id * id);

/**
 * Update a record to the storage.
 *
 * @param storage where create the record.
 * @param id of record to update.
 * @param content the record content.
 * @return the new number of version of updated record.
 */
int o_storage_update_record(struct o_storage * storage, struct o_record_id * id, struct o_raw_buffer * content);

/**
 * Delete a record from a storage.
 *
 * @param storage the storage where delete the record.
 * @param id the identifier of record to delete.
 * @param vesion the version of record to delete.
 */
int o_storage_delete_record(struct o_storage * storage, struct o_record_id * id, int version);

/**
 * Retrieve the names of clusters in storage.
 *
 * @param storage storage where retrieve the names.
 * @param names_count the count of names retrieved names.
 * @return the names of clusters in storage.
 */
char ** o_storage_get_cluster_names(struct o_storage * storage, int * names_count);

/**
 * Retrieve the id of cluster from the name.
 * @param the storage where search the cluster.
 * @param name the name of cluster.
 * @return the identifier of cluster.
 */
int o_storage_get_cluster_id_by_name(struct o_storage * storage, char * name);

/*! Retrieve the default cluster id.
 *
 * \param storage where search
 * \return the identifier of default cluster.
 */
int o_storage_get_default_cluser_id(struct o_storage * storage);

/**
 * Commit a transaction to the storage.
 *
 * @param storage where commit the transuction.
 * @param transaction to commit.
 */
void o_storage_commit_transaction(struct o_storage *storage, struct o_transaction * transaction);

/*! \brief set the callback to the storage.
 *
 * \param storage where set the callback.
 * \param add_info additional info for the callback call.
 * \param callback to invoke.
 */
void o_storage_set_callback(struct o_storage *storage, void * add_info, query_result_callback callback);

/*! \brief get the callback from the storage.
 *
 * \param storage where get the callback.
 * \param add_info additional info of the callback.
 * \return callback of the storage.
 */
query_result_callback o_storage_get_callback(struct o_storage *storage, void ** add_info);

/*!\brief retrieve the metadata of the storage.
 *
 * \param storage to retrieve metedata.
 * \return the raw buffer that represent the metadata.
 */
struct o_raw_buffer * o_storage_get_metadata(struct o_storage *storage);

/*! \brief Release the current storage.
 * reference count decrement.
 *
 * \param storage to release.
 */
void o_storage_release(struct o_storage * storage);

/*! \brief increase an reference to the storage.
 *
 * \param storage to refer.
 */
void o_storage_reference(struct o_storage * storage);

/*! \brief Close the current storage.
 *
 * \param storage to close.
 */
void o_storage_close(struct o_storage * storage);

/** Free the storage structure.
 *
 * @param storage to free.
 */
void o_storage_free(struct o_storage * storage);

#endif /* O_STORAGE_H_ */
