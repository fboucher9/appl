/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_buf.h>

#include <appl_property_types.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_property.h>

#include <appl_property_std.h>

#include <appl_context.h>

#include <appl_allocator.h>

#include <appl_heap.h>

struct appl_property_node
{
    unsigned int
        i_id;

    enum appl_property_type
        e_type;

    union appl_property_value
        o_value;

}; /* struct appl_property_node */

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
        a_nodes[i_id].e_type =
            e_type;

        a_nodes[i_id].o_value =
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
            e_type == a_nodes[i_id].e_type)
        {
            *(
                p_value) =
                a_nodes[i_id].o_value;

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
    a_nodes(),
    m_count(),
    b_nodes_allocated()
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
                    a_nodes));

        if (
            appl_status_ok
            == e_status)
        {
            unsigned int
                i;

            for (
                i = 0u;
                i < m_count;
                i ++)
            {
                a_nodes[i].e_type =
                    appl_property_type_default;

                a_nodes[i].o_value.p_value =
                    0;
            }

            b_nodes_allocated =
                true;
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
        b_nodes_allocated)
    {
        appl_size_t
            i_placement_length;

        i_placement_length =
            m_count * sizeof(a_nodes[0u]);

        m_context->m_heap->v_free(
            i_placement_length,
            a_nodes);

        a_nodes =
            0;

        b_nodes_allocated =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

/* end-of-file: appl_property_std.cpp */
