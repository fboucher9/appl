/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_hash_handle.h>

#include <hash/appl_hash_service.h>

/*

*/
enum appl_status
appl_hash_create(
    struct appl_context * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance)
{
    return
        appl_hash_service::s_create(
            p_context,
            p_descriptor,
            r_instance);

} /* appl_hash_create() */

/*

*/
enum appl_status
appl_hash_destroy(
    struct appl_hash * const
        p_instance)
{
    return
        appl_hash_service::s_destroy(
            p_instance);

} /* appl_hash_destroy() */

/*

*/
struct appl_object *
appl_hash_parent(
    struct appl_hash * const
        p_hash)
{
    return
        appl_hash_service::s_parent(
            p_hash);

} /* appl_hash_destroy() */

/*

*/
void
appl_hash_insert(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list)
{
    appl_hash_service::s_insert(
        p_hash,
        p_key,
        i_key_len,
        p_list);

} /* appl_hash_insert() */

/*

*/
char
appl_hash_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * * const
        r_list)
{
    return
        appl_hash_service::s_lookup(
            p_hash,
            p_key,
            i_key_len,
            r_list) ? 1 : 0;

} /* appl_hash_lookup() */

/*

*/
void
appl_hash_iterate(
    struct appl_hash * const
        p_hash,
    void (
        * p_callback)(
        void * const
            p_context,
        struct appl_list * const
            p_list),
    void * const
        p_context)
{
    appl_hash_service::s_iterate(
        p_hash,
        p_callback,
        p_context);

} /* appl_hash_iterate() */

/* end-of-file: appl_hash_handle.cpp */
