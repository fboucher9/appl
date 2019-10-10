/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <env/appl_env.h>

#include <misc/appl_unused.h>

#if defined APPL_DEBUG
#include <debug/appl_debug_impl.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_env::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        struct appl_string * * const
            r_string) const
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_string);
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "env get not implemented\n");
#endif /* #if defined APPL_DEBUG */
    return
        appl_status_not_implemented;
} // v_get()

//
//
//
enum appl_status
    appl_env::v_query(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void (* p_query_callback)(
            void * const
                p_query_context,
            unsigned char const * const
                p_value_min,
            unsigned char const * const
                p_value_max),
        void * const
            p_query_context) const
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_query_callback,
        p_query_context);
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "env query not implemented\n");
#endif /* #if defined APPL_DEBUG */
    return
        appl_status_not_implemented;
} // v_query()

//
//
//
enum appl_status
    appl_env::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        unsigned char const * const
            p_value_min,
        unsigned char const * const
            p_value_max)
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_value_min,
        p_value_max);
#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "env set not implemented\n");
#endif /* #if defined APPL_DEBUG */
    return
        appl_status_not_implemented;
} // v_set()

//
//
//
appl_env::appl_env(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_env::~appl_env()
{
}

/* end-of-file: appl_env.cpp */
