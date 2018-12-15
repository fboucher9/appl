/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_unused.h>

#if defined APPL_DEBUG

#include <debug/appl_debug_impl.h>

#include <backtrace/appl_backtrace_impl.h>

#endif /* #if defined APPL_DEBUG */

//
//
//
appl_object::appl_object(
    struct appl_context * const
        p_context) :
    m_context(
        p_context)
{
}

//
//
//
appl_object::~appl_object()
{
}

//
//
//
void *
appl_object::operator new(
    appl_size_t const
        i_buf_len)
{
    static
    unsigned char
    g_uiDummy = 123;

    appl_unused(
        i_buf_len);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "incorrect use of operator new\n");
#endif /* #if defined APPL_DEBUG */

    void * const
        p_result =
        &(
            g_uiDummy);

    return
        p_result;

} // operator new

//
//
//
void
appl_object::operator delete(
    void *
        p_buf)
{
    appl_unused(
        p_buf);
} // operator delete

//
//
//
void *
appl_object::operator new(
    appl_size_t const
        i_buf_len,
    void * const
        p_placement)
{
    appl_unused(
        i_buf_len);
    return
        p_placement;
} // operator new

//
//
//
void
appl_object::operator delete (
    void *
        p_buf,
    void * const
        p_placement)
{
    appl_unused(
        p_buf,
        p_placement);

#if defined APPL_DEBUG
    appl_debug_impl::s_print0(
        "incorrect use of operator delete\n");
#endif /* #if defined APPL_DEBUG */

} // operator delete

//
//
//
enum appl_status
    appl_object::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_object::v_cleanup(void)
{
#if defined APPL_DEBUG
    appl_backtrace_impl::s_ouch(
        "object cleanup not implemented\n");
#endif /* #if defined APPL_DEBUG */

    return
        sizeof(struct appl_object);

} // v_cleanup()

//
//
//
struct appl_context *
    appl_object::get_context(void) const
{
    return
        m_context;

} // get_context()

/* end-of-file: appl_object.cpp */
