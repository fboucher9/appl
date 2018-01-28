/* See LICENSE for license details */

/*

*/

#include <stdlib.h>

#include <string.h>

#include "appl.h"

#include "appl_object.h"

#include "appl_options.h"

#include "appl_options_std.h"

//
//
//
enum appl_status
appl_options_std::create_instance(
    class appl_client * const
        p_client,
    struct appl_options_descriptor const * const
        p_options_descriptor,
    class appl_options_std * * const
        r_options_std)
{
    enum appl_status
        e_status;

    class appl_options_std * const
        p_options_std =
        new
            class appl_options_std;

    if (
        p_options_std)
    {
        e_status =
            p_options_std->init(
                p_client,
                p_options_descriptor);

        if (
            appl_status_ok
            == e_status)
        {
            *(
                r_options_std) =
                p_options_std;
        }
        else
        {
            delete
                p_options_std;
        }
    }
    else
    {
        e_status =
            appl_status_out_of_memory;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_options_std::appl_options_std() :
    appl_options(),
    m_placement_ptr(),
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

enum appl_status
appl_options_std::init(
    class appl_client * const
        p_client,
    struct appl_options_descriptor const * const
        p_options_descriptor)
{
    enum appl_status
        e_status;

    m_client =
        p_client;

    unsigned long int const
        i_count =
        static_cast<unsigned long int>(
            p_options_descriptor->p_buf_max
            - p_options_descriptor->p_buf_min);

    unsigned long int
        i_placement_length =
        static_cast<unsigned long int>(
            i_count
            * sizeof(
                struct appl_buf));

    m_placement_ptr =
        malloc(
            i_placement_length);

    if (
        m_placement_ptr)
    {
        memcpy(
            m_placement_ptr,
            p_options_descriptor->p_buf_min,
            i_placement_length);

        m_buf_min =
            static_cast<struct appl_buf *>(
                m_placement_ptr);

        m_buf_max =
            m_buf_min
            + i_count;
    }
    else
    {
        e_status =
            appl_status_out_of_memory;
    }

    return
        e_status;

} // init()

enum appl_status
appl_options_std::cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_placement_ptr)
    {
        free(
            m_placement_ptr);

        m_placement_ptr =
            static_cast<void *>(
                0);
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

enum appl_status
appl_options_std::destroy(void)
{
    enum appl_status
        e_status;

    e_status =
        cleanup();

    if (
        appl_status_ok == e_status)
    {
        delete
            this;
    }

    return
        e_status;

} // destroy()

/* end-of-file: appl_options_std.cpp */
