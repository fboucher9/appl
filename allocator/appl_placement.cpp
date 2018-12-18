/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <allocator/appl_allocator.h>

#include <allocator/appl_placement.h>

#include <appl_unused.h>

//
//
//
appl_placement::appl_placement(
    struct appl_context * const
        p_context) :
    appl_allocator(
        p_context),
    m_descriptor()
{
}

//
//
//
appl_placement::~appl_placement()
{
}

//
//
//
enum appl_status
    appl_placement::f_init(
        struct appl_placement_descriptor const * const
            p_descriptor)
{
    m_descriptor =
        *(
            p_descriptor);

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_placement::v_cleanup(void)
{
    return
        sizeof(class appl_placement);

} // v_cleanup()

//
//
//
enum appl_status
    appl_placement::v_alloc(
        appl_size_t const
            i_buf_len,
        void * * const
            r_buf)
{
    appl_unused(
        i_buf_len);

    *(
        r_buf) =
        m_descriptor.p_placement;

    return
        appl_status_ok;

} // v_alloc()

//
//
//
enum appl_status
    appl_placement::v_free(
        appl_size_t const
            i_buf_len,
        void * const
            p_buf)
{
    appl_unused(
        i_buf_len,
        p_buf);

    return
        appl_status_ok;

} // v_free()

/* end-of-file: appl_placement.cpp */
