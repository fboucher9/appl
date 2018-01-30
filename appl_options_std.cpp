/* See LICENSE for license details */

/*

*/

#include <string.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_options.h"

#include "appl_options_std.h"

#include "appl_client.h"

#include "appl_heap.h"

//
//
//
enum appl_status
appl_options_std::create_instance(
    class appl_client * const
        p_client,
    struct appl_options_std_descriptor const * const
        p_options_std_descriptor,
    class appl_options_std * * const
        r_options_std)
{
    enum appl_status
        e_status;

    class appl_object *
        p_object;

    e_status =
        appl_object::create_instance(
            p_client,
            sizeof(
                class appl_options_std),
            &(
                appl_options_std::placement_new),
            p_options_std_descriptor,
            &(
                p_object));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_options_std) =
            reinterpret_cast<class appl_options_std *>(
                p_object);
    }

    return
        e_status;

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
        m_client->m_heap->alloc_memory(
            &(
                m_placement_buf),
            i_placement_length);

    if (
        appl_status_ok == e_status)
    {
        m_buf_min =
            static_cast<struct appl_buf *>(
                m_placement_buf.o_min.p_void);

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
                p_options_std_descriptor->p_arg_min[argi]
                + strlen(p_options_std_descriptor->p_arg_min[argi]);
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

    m_client->m_heap->free_memory(
        &(
            m_placement_buf));

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
