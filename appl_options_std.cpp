/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_options.h"

#include "appl_options_std.h"

#include "appl_string.h"

#include "appl_context.h"

#include "appl_heap.h"

//
//
//
enum appl_status
appl_options_std::s_create(
    struct appl_context * const
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

    e_status =
        m_context->m_heap->alloc_object_array(
            i_count,
            &(
                m_buf_min));

    if (
        appl_status_ok == e_status)
    {
        m_buf_max =
            m_buf_min
            + i_count;

        unsigned long int
            argi;

        argi = 0;

        while (
            (
                appl_status_ok == e_status)
            && (
                argi < i_count))
        {
            unsigned char const * const
                p_buf_min =
                p_options_std_descriptor->p_arg_min[argi];

            unsigned char const *
                p_buf_max =
                p_buf_min;

            while (*(p_buf_max))
            {
                p_buf_max ++;
            }

            e_status =
                appl_string::s_create(
                    m_context,
                    p_buf_min,
                    p_buf_max,
                    p_buf_min,
                    0,
                    m_buf_min + argi);

            if (
                appl_status_ok == e_status)
            {
                argi++;
            }
            else
            {
                while (argi)
                {
                    argi --;

                    struct appl_string * const
                        p_string =
                        m_buf_min[argi];

                    p_string->destroy();

                    m_buf_min[argi] = 0;
                }
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

    struct appl_string * *
        p_buf_it;

    p_buf_it =
        m_buf_min;

    while (
        p_buf_it
        < m_buf_max)
    {
        struct appl_string * const
            p_string =
            *(p_buf_it);

        p_string->destroy();

        *(p_buf_it) =
            0;

        p_buf_it ++;
    }

    m_context->m_heap->v_free(
        m_buf_min);

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
appl_options_std::v_count(
    unsigned long int * const
        r_count) const
{
    enum appl_status
        e_status;

    unsigned long int const
        i_count =
        static_cast<unsigned long int>(
            m_buf_max
            - m_buf_min);

    *(
        r_count) =
        i_count;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_count()

//
//
//
enum appl_status
appl_options_std::v_get(
    unsigned long int const
        i_index,
    unsigned char const * * const
        r_buf_min,
    unsigned char const * * const
        r_buf_max) const
{
    enum appl_status
        e_status;

    if (
        (m_buf_min + i_index) < m_buf_max)
    {
        struct appl_string * const
            p_string =
            m_buf_min[i_index];

        e_status =
            p_string->v_read(
                r_buf_min,
                r_buf_max);
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_get()

/* end-of-file: appl_options_std.cpp */
