/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <options/appl_options.h>

#include <appl_unused.h>

#if defined APPL_DEBUG
#include <appl_debug_handle.h>
#endif /* #if defined APPL_DEBUG */

//
//
//
enum appl_status
    appl_options::v_count(
        unsigned long int * const
            r_count) const
{
    appl_unused(
        r_count);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "options count not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
} // v_count()

//
//
//
enum appl_status
    appl_options::v_get(
        unsigned long int const
            i_index,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max) const
{
    appl_unused(
        i_index,
        r_buf_min,
        r_buf_max);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "options get not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;
} // v_get()

//
//
//
enum appl_status
    appl_options::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            p_count,
        char * const
            p_ready)
{
    appl_unused(
        p_buf_min,
        p_buf_max,
        p_count,
        p_ready);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "options write not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_write()

//
//
//
enum appl_status
    appl_options::v_append_argument(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max)
{
    appl_unused(
        p_buf_min,
        p_buf_max);

#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "options append argument not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_append_argument()

//
//
//
enum appl_status
    appl_options::v_reset(void)
{
#if defined APPL_DEBUG
    appl_debug_print0(
        m_context,
        "options reset not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        appl_status_not_implemented;

} // v_reset()

//
//
//
appl_options::appl_options(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_options::~appl_options()
{
}

/* end-of-file: appl_options.cpp */
