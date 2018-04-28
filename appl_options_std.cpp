/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_options.h>

#include <appl_options_std.h>

#include <appl_string.h>

#include <appl_context.h>

#include <appl_heap.h>

#include <appl_buf0.h>

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
        r_options)
{
    enum appl_status
        e_status;

    class appl_options_std *
        p_options_std;

    e_status =
        appl_object::s_create(
            p_context,
            (&
                appl_options_std::placement_new),
            (&
                appl_options_std::init),
            p_options_std_descriptor,
            &(
                p_options_std));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_options) =
            p_options_std;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_options_std::appl_options_std() :
    appl_options(),
    m_descriptor()
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
void
    appl_options_std::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_options_std;

} // placement_new()

//
//
//
enum appl_status
appl_options_std::init(
    struct appl_options_std_descriptor const * const
        p_options_std_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_options_std_descriptor);

    e_status =
        appl_status_ok;

    return
        e_status;

} // init()

//
//
//
enum appl_status
appl_options_std::v_cleanup(void)
{
    enum appl_status
        e_status;

    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

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
            m_descriptor.p_arg_max
            - m_descriptor.p_arg_min);

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
        (m_descriptor.p_arg_min + i_index) < m_descriptor.p_arg_max)
    {
        unsigned char const *
            p_arg0;

        p_arg0 =
            m_descriptor.p_arg_min[i_index];

        *(
            r_buf_min) =
            p_arg0;

        *(
            r_buf_max) =
            p_arg0
            + appl_buf0_len(
                p_arg0);

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

} // v_get()

/* end-of-file: appl_options_std.cpp */
