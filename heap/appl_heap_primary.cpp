/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <list/appl_list.h>

#include <heap/appl_heap_primary.h>

#if defined APPL_HAVE_COVERAGE
#include <coverage/appl_coverage.h>
#endif /* #if defined APPL_HAVE_COVERAGE */

#include <stdlib.h>

//
//
//
appl_heap_primary::appl_heap_primary() :
    m_mmap_iterator(),
    m_mmap_end(),
    m_segments()
{
}

//
//
//
appl_heap_primary::~appl_heap_primary()
{
}

//
//
//
enum appl_status
    appl_heap_primary::f_init(
        unsigned char * const
            p_mmap_begin,
        unsigned char * const
            p_mmap_end)
{
    enum appl_status
        e_status;

    m_mmap_iterator =
        p_mmap_begin;

    m_mmap_end =
        p_mmap_end;

    appl_list_init(
        &(
            m_segments));

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_heap_primary::f_cleanup(void)
{
    enum appl_status
        e_status;

    // free all segments
    while (m_segments.o_next.p_node != &(m_segments))
    {
        struct appl_list *
            p_segment;

        p_segment =
            m_segments.o_next.p_node;

        appl_list_join(
            p_segment,
            p_segment);

        free(
            p_segment);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_cleanup()

static
appl_size_t const
    g_appl_heap_primary_segment_length =
    256ul * 1024ul;

static
appl_size_t const
g_appl_heap_primary_max_alloc_length =
    g_appl_heap_primary_segment_length
    - sizeof(struct appl_list);

//
//
//
enum appl_status
    appl_heap_primary::f_alloc(
        appl_size_t const
            i_len,
        void * * const
            r_buf)
{
    enum appl_status
        e_status;

    // Validate len
    if (
        g_appl_heap_primary_max_alloc_length
        >= i_len)
    {
        // Is there room in current segment?
        if (
            (m_mmap_iterator + i_len) > m_mmap_end)
        {
            f_grow();
        }

        if (
            (m_mmap_iterator + i_len) <= m_mmap_end)
        {
            *(
                r_buf) =
                m_mmap_iterator;

            m_mmap_iterator +=
                i_len;

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_out_of_memory;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_alloc()

//
//
//
void
    appl_heap_primary::f_grow(void)
{
    union appl_heap_segment_ptr
        o_segment_ptr;

    // Add an extra segment
    o_segment_ptr.p_void =
#if defined APPL_HAVE_COVERAGE
        appl_coverage_check() ? NULL :
#endif /* #if defined APPL_HAVE_COVERAGE */
        malloc(
            g_appl_heap_primary_segment_length);

    if (
        o_segment_ptr.p_void)
    {
        appl_list_init(
            o_segment_ptr.p_list);

        appl_list_join(
            o_segment_ptr.p_list,
            &(
                m_segments));

        m_mmap_iterator =
            o_segment_ptr.p_uchar
            + sizeof(struct appl_list);

        m_mmap_end =
            o_segment_ptr.p_uchar
            + g_appl_heap_primary_segment_length;
    }

} // f_grow()

/* end-of-file: appl_heap_primary.cpp */
