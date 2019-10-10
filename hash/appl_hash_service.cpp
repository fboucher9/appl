/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <appl_hash_handle.h>

#include <hash/appl_hash_service.h>

#include <appl_object.h>

#include <list/appl_list.h>

#include <hash/appl_hash.h>

#include <context/appl_context.h>

#include <appl_allocator_handle.h>

//
//
//
enum appl_status
appl_hash_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_hash_descriptor const * const
        p_descriptor,
    struct appl_hash * * const
        r_instance)
{
    enum appl_status
        e_status;

    struct appl_allocator * const
        p_allocator =
        p_context->v_allocator();

    e_status =
        appl_new(
            p_allocator,
            p_descriptor,
            r_instance);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_hash_service::s_destroy(
    struct appl_hash * const
        p_hash)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_hash->get_context();

    struct appl_allocator * const
        p_allocator =
        p_context->v_allocator();

    e_status =
        appl_delete(
            p_allocator,
            p_hash);

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_hash_service::s_parent(
    struct appl_hash * const
        p_hash)
{
    return
        p_hash;
} // s_parent()

//
//
//
void
appl_hash_service::s_insert(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len,
    struct appl_list * const
        p_list)
{
    p_hash->f_insert(
        p_key,
        i_key_len,
        p_list);
} // s_insert()

//
//
//
bool
appl_hash_service::s_lookup(
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
        p_hash->f_lookup(
            p_key,
            i_key_len,
            r_list);
} // s_lookup()

//
//
//
void
appl_hash_service::s_iterate(
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
    p_hash->f_iterate(
        p_callback,
        p_context);
} // s_iterate()

/* end-of-file: appl_hash_service.cpp */
