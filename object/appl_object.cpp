/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_unused.h>

#include <allocator/appl_allocator.h>

//
//
//
enum appl_status
    appl_object::v_destroy(void)
{
    struct appl_allocator * const
        p_allocator =
        m_destroyer;

    appl_size_t const
        i_placement_length =
        m_destroyer_length;

    void * const
        p_placement =
        this;

    enum appl_status const
        e_status =
        v_cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        delete
            this;

        if (
            p_allocator)
        {
            p_allocator->v_free(
                i_placement_length,
                p_placement);
        }
    }

    return
        e_status;

} // v_destroy()

//
//
//
appl_object::appl_object() :
    m_context(),
    m_destroyer(),
    m_destroyer_length()
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
enum appl_status
    appl_object::v_cleanup(void)
{
    delete
        this;

    return
        appl_status_ok;

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

//
//
//
struct appl_allocator *
    appl_object::get_allocator(void) const
{
    return
        m_destroyer;

} // get_allocator()

//
//
//
void
    appl_object::set_allocator(
        struct appl_allocator * const
            p_allocator)
{
    m_destroyer =
        p_allocator;

} // set_allocator()

//
//
//
appl_size_t
    appl_object::get_placement_length(void) const
{
    return
        m_destroyer_length;

} // get_placement_length()

//
//
//
void
    appl_object::set_placement_length(
        appl_size_t const
            i_placement_length)
{
    m_destroyer_length =
        i_placement_length;

} // set_placement_length()

/* end-of-file: appl_object.cpp */
