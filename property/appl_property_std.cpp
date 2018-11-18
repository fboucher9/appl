/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

#include <property/appl_property_types.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <property/appl_property.h>

#include <property/appl_property_std.h>

#include <context/appl_context.h>

#include <allocator/appl_allocator.h>

#include <heap/appl_heap.h>

#include <appl_convert.h>

#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
enum appl_status
    appl_property_std::s_create(
        struct appl_allocator * const
            p_allocator,
        unsigned int const
            i_count,
        struct appl_property * * const
            r_property)
{
    enum appl_status
        e_status;

    struct appl_property_std_descriptor
        o_property_std_descriptor;

    o_property_std_descriptor.i_count =
        i_count;

    struct appl_property_std *
        p_property_std;

    e_status =
        p_allocator->alloc_object(
            &(
                o_property_std_descriptor),
            &(
                p_property_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_property) =
            p_property_std;
    }

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
    appl_property_std::v_set(
        unsigned int const
            i_id,
        enum appl_property_type const
            e_type,
        union appl_property_value const * const
            p_value)
{
    enum appl_status
        e_status;

    if (
        i_id < m_count)
    {
        a_types[i_id] =
            appl_convert::to_uchar(
                e_type);

        a_values[i_id] =
            *(
                p_value);

        e_status =
            appl_status_ok;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_set()

//
//
//
enum appl_status
    appl_property_std::v_get(
        unsigned int const
            i_id,
        enum appl_property_type const
            e_type,
        union appl_property_value * const
            p_value) const
{
    enum appl_status
        e_status;

    if (
        i_id < m_count)
    {
        if (
            e_type == a_types[i_id])
        {
            *(
                p_value) =
                a_values[i_id];

            e_status =
                appl_status_ok;
        }
        else
        {
            e_status =
                appl_status_fail;
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // v_get()

//
//
//
appl_property_std::appl_property_std() :
    appl_property(),
    a_values(),
    a_types(),
    m_count(),
    b_values_allocated(),
    b_types_allocated()
{
}

//
//
//
appl_property_std::~appl_property_std()
{
}

//
//
//
enum appl_status
    appl_property_std::f_init(
        struct appl_property_std_descriptor const * const
            p_property_std_descriptor)
{
    enum appl_status
        e_status;

    m_count =
        p_property_std_descriptor->i_count;

    if (
        m_count)
    {
        e_status =
            m_context->m_heap->alloc_structure_array(
                m_count,
                &(
                    a_values));

        if (
            appl_status_ok
            == e_status)
        {
            b_values_allocated =
                true;

            e_status =
                m_context->m_heap->alloc_structure_array(
                    m_count,
                    &(
                        a_types));

            if (
                appl_status_ok
                == e_status)
            {
                b_types_allocated =
                    true;

                unsigned int
                    i;

                for (
                    i = 0u;
                    i < m_count;
                    i ++)
                {
                    a_types[i] =
                        appl_property_type_default;

                    a_values[i].p_value =
                        0;
                }

                if (
                    appl_status_ok
                    != e_status)
                {
                    m_context->m_heap->free_structure_array(
                        m_count,
                        a_types);

                    b_types_allocated =
                        false;
                }
            }

            if (
                appl_status_ok
                != e_status)
            {
                m_context->m_heap->free_structure_array(
                    m_count,
                    a_values);

                b_values_allocated =
                    false;
            }
        }
    }
    else
    {
        e_status =
            appl_status_ok;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_property_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    if (
        b_types_allocated)
    {
        m_context->m_heap->free_structure_array(
            m_count,
            a_types);

        a_types =
            0;

        b_types_allocated =
            false;
    }

    if (
        b_values_allocated)
    {
        m_context->m_heap->free_structure_array(
            m_count,
            a_values);

        a_values =
            0;

        b_values_allocated =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_property_std.cpp */
