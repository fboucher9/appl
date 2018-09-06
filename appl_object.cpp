/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_context.h>

#include <appl_heap.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_object::destroy(void)
{
    struct appl_context * const
        p_context =
        m_context;

    enum appl_status const
        e_status =
        v_cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        class appl_heap * const
            p_heap =
            p_context->m_heap;

        void * const
            p_placement =
            this;

        delete
            this;

        /* Free memory */
        p_heap->v_free(
            m_placement_length,
            p_placement);
    }

    return
        e_status;

} // destroy()

//
//
//
appl_object::appl_object() :
    m_context(),
    m_placement_length()
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
    appl_object::init_dummy(void)
{
    return
        appl_status_ok;

} // init_dummy()

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
enum appl_status
    appl_object::alloc_placement(
        struct appl_context * const
            p_context,
        appl_size_t const
            i_placement_length,
        void * * const
            r_placement)
{
    return
        p_context->m_heap->v_alloc(
            i_placement_length,
            r_placement);

} // alloc_placement()

//
//
//
void
    appl_object::free_placement(
        struct appl_context * const
            p_context,
        appl_size_t const
            i_placement_length,
        void * const
            p_placement)
{
    p_context->m_heap->v_free(
        i_placement_length,
        p_placement);

} // free_placement()

/* end-of-file: appl_object.cpp */
