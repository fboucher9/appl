/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_hash_handle.h>

#include <hash/appl_hash_service.h>

#include <appl_object.h>

#include <appl_list.h>

#include <hash/appl_hash.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

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
    struct appl_allocator * const
        p_allocator =
        p_context->m_allocator;

    return
        p_allocator->alloc_object(
            p_descriptor,
            r_instance);

} // s_create()

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
struct appl_list *
appl_hash_service::s_lookup(
    struct appl_hash * const
        p_hash,
    void const * const
        p_key,
    unsigned long int const
        i_key_len)
{
    return
        p_hash->f_lookup(
            p_key,
            i_key_len);
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
