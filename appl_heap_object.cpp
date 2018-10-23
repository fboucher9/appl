/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_heap_object.h>

#include <appl_context.h>

#include <appl_heap.h>

//
//
//
enum appl_status
    appl_heap_object::v_destroy(void)
{
    struct appl_context * const
        p_context =
        m_context;

    struct appl_heap * const
        p_heap =
        p_context->m_heap;

    void * const
        p_placement =
        this;

    appl_size_t const
        i_placement_length =
        m_placement_length;

    enum appl_status const
        e_status =
        v_cleanup();

    if (
        appl_status_ok
        == e_status)
    {
        delete
            this;

        /* Free memory */
        p_heap->v_free(
            i_placement_length,
            p_placement);
    }

    return
        e_status;

} // v_destroy()

//
//
//
appl_size_t
    appl_heap_object::get_placement_length(void) const
{
    return
        m_placement_length;

} // get_placement_length()

//
//
//
void
    appl_heap_object::set_placement_length(
        appl_size_t const
            i_placement_length)
{
    m_placement_length =
        i_placement_length;

} // set_placement_length()

//
//
//
appl_heap_object::appl_heap_object() :
    appl_object(),
    m_placement_length()
{
}

//
//
//
appl_heap_object::~appl_heap_object()
{
}

/* end-of-file: appl_heap_object.cpp */
