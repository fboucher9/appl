/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_unused.h>

#include <appl_allocator_handle.h>

#if defined APPL_DEBUG

#include <backtrace/appl_backtrace_impl.h>

#if defined APPL_OS_LINUX

#include <unistd.h>

#endif /* #if defined APPL_OS_LINUX */

#endif /* #if defined APPL_DEBUG */

//
//
//
appl_object::appl_object() :
    m_context()
{
}

//
//
//
appl_object::~appl_object()
{
}

void *
appl_object::operator new(
    appl_size_t const
        i_buf_len)
{
    static unsigned char g_uiDummy = 123;
    appl_unused(
        i_buf_len);
    void * const
        p_result =
        &(
            g_uiDummy);
    return
        p_result;
} // operator new

void
appl_object::operator delete(
    void *
        p_buf)
{
    appl_unused(
        p_buf);
} // operator delete

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
#if defined APPL_OS_LINUX
    {
        static unsigned char const s_msg[] =
            "object cleanup not implemented\n";
        write(1, s_msg, sizeof(s_msg) - 1);
    }
#endif /* #if defined APPL_OS_LINUX */
    {
        void const *
            a_stack[8u];

        appl_size_t
            i_count;

        if (
            appl_status_ok
            == appl_backtrace_impl::s_capture(
                a_stack,
                8u,
                &(
                    i_count)))
        {
            appl_backtrace_impl::s_report(
                a_stack,
                i_count);
        }
    }
#endif /* #if defined APPL_DEBUG */

    return
        0;

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

//
//
//
void
    appl_object::set_context(
        struct appl_context * const
            p_context)
{
    m_context =
        p_context;

} // set_context()

/* end-of-file: appl_object.cpp */
