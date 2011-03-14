#ifndef O_RECORD_ID_H_
#define O_RECORD_ID_H_

#define CLUSTER_ID_INVALID	-1
#define CLUSTER_POS_INVALID	 -1

struct o_record_id;

/** Create a new record id with empty values.
 *
 * @return a new instance of record id.
 */
struct o_record_id * o_record_id_new_empty();

/** Create a new record id.
 *
 * @param cluster_id the identifier of cluster.
 * @param record_id the identifier of record.
 * @return a new instance of record id.
 */
struct o_record_id * o_record_id_new(int cluster_id, long long record_id);

/** Retrieve the identifier of cluster from a record id.
 *
 * @param o_id the record identifier where retrieve the cluster identifier.
 * @return the cluster identifier.
 */
int o_record_id_cluster_id(struct o_record_id * o_id);

/** Retrieve the identifier of record from a record id.
 *
 * @param o_id the record identifier where retrieve the in cluster record identifier.
 * @return the in cluster record identifier.
 */
long long o_record_id_record_id(struct o_record_id * o_id);

/** Retrieve if the id represent a persistent or transient id.
 *
 * \param id to check.
 * \return 1 if is transient 0 if persistent.
 */
int o_record_id_is_new(struct o_record_id * o_id);

/*! \brief Increment a reference to record id.
 *
 * \param o_id to increment reference.
 */
void o_record_id_refer(struct o_record_id * o_id);

/*! \brief Retrieve the record id serialized sach a string.
 *
 * \param o_id to serialize.
 * \return the string representation of o_id.
 */
char * o_record_id_string(struct o_record_id * o_id);

/** Release an reference to record id.
 *
 * @param o_id the record id to release.
 */
void o_record_id_release(struct o_record_id * o_id);

#endif /* O_RECORD_ID_H_ */
