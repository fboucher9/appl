/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_buf.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_options.h"

#include "appl_options_std.h"

#include "appl_context.h"

#include "appl_heap.h"

#include "appl_options_descriptor.h"

//
//
//
enum appl_status
appl_options_std::create_instance(
    class appl_context * const
        p_context,
    struct appl_options_std_descriptor const * const
        p_options_std_descriptor,
    class appl_options * * const
        r_options_std)
{
    return
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_options_std),
            &(
                appl_options_std::placement_new),
            p_options_std_descriptor,
            r_options_std);

} // create_instance()

//
//
//
appl_options_std::appl_options_std() :
    appl_options(),
    m_placement_buf(),
    m_buf_min(),
    m_buf_max()
{
}

//
//
//
appl_options_std::~appl_options_std()
{
}

//
//
//
enum appl_status
appl_options_std::init(
    void const * const
        p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_options_std_descriptor const * const
        p_options_std_descriptor =
        static_cast<struct appl_options_std_descriptor const *>(
            p_descriptor);

    unsigned long int const
        i_count =
        static_cast<unsigned long int>(
            p_options_std_descriptor->p_arg_max
            - p_options_std_descriptor->p_arg_min);

    unsigned long int
        i_placement_length =
        static_cast<unsigned long int>(
            i_count
            * sizeof(
                struct appl_buf));

    e_status =
        m_context->m_heap->v_alloc(
            i_placement_length,
            &(
                m_placement_buf));

    if (
        appl_status_ok == e_status)
    {
        m_buf_min =
            static_cast<struct appl_buf *>(
                m_placement_buf);

        m_buf_max =
            m_buf_min
            + i_count;

        for (
            unsigned long int argi=0;
            argi<i_count;
            argi++)
        {
            m_buf_min[argi].o_min.pc_void =
                p_options_std_descriptor->p_arg_min[argi];

            m_buf_min[argi].o_max.pc_void =
                p_options_std_descriptor->p_arg_min[argi];

            while (*(m_buf_min[argi].o_max.pc_uchar))
            {
                m_buf_min[argi].o_max.pc_uchar ++;
            }
        }

        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // init()

//
//
//
enum appl_status
appl_options_std::cleanup(void)
{
    enum appl_status
        e_status;

    m_context->m_heap->v_free(
        m_placement_buf);

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
appl_options_std::query(
    struct appl_options_descriptor * const
        p_options_descriptor)
{
    enum appl_status
        e_status;

    p_options_descriptor->p_buf_min =
        m_buf_min;

    p_options_descriptor->p_buf_max =
        m_buf_max;

    e_status =
        appl_status_ok;

    return
        e_status;

} // query()

/* end-of-file: appl_options_std.cpp */
