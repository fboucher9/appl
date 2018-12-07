/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <dict/appl_dict.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_dict::v_set(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * const
            p_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        p_value);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "dict set not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_set()

//
//
//
enum appl_status
    appl_dict::v_get(
        unsigned char const * const
            p_name_min,
        unsigned char const * const
            p_name_max,
        void * * const
            r_value)
{
    appl_unused(
        p_name_min,
        p_name_max,
        r_value);

#if defined APPL_DEBUG
    {
        static unsigned char const s_msg[] =
            "dict get not implemented\n";
        appl_debug_print0(
            m_context,
            s_msg);
    }
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_get()

//
//
//
appl_dict::appl_dict(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_dict::~appl_dict()
{
}

/* end-of-file: appl_dict.cpp */
