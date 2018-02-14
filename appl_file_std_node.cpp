/* See LICENSE for license details */

/*

*/

#include <unistd.h>

#include <stdio.h>

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_node.h"

#include "appl_file_std_node.h"

#include "appl_buf.h"

#include "appl_file_descriptor.h"

//
//
//
enum appl_status
    appl_file_std_node::create_instance(
        class appl_context * const
            p_context,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        class appl_file_node * * const
            r_file_node)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::create_instance(
            p_context,
            sizeof(
                class appl_file_std_node),
            &(
                appl_file_std_node::placement_new),
            p_file_descriptor,
            reinterpret_cast<class appl_object * *>(
                r_file_node));

    return
        e_status;

} // create_instance()

//
//
//
appl_file_std_node::appl_file_std_node() :
    appl_file_node(),
    m_fd(),
    m_close(false)
{
}

//
//
//
appl_file_std_node::~appl_file_std_node()
{
}

//
//
//
void
    appl_file_std_node::placement_new(
        void * const
            p_placement)
{
    new (p_placement)
        class appl_file_std_node;

} // placement_new()

//
//
//
enum appl_status
    appl_file_std_node::init(
        void const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    struct appl_file_descriptor const * const
        p_file_descriptor =
        static_cast<struct appl_file_descriptor const *>(
            p_descriptor);

    if (
        appl_file_type_stdin == p_file_descriptor->e_type)
    {
        m_fd =
            STDIN_FILENO;

        e_status =
            appl_status_ok;
    }
    else if (
        appl_file_type_stdout == p_file_descriptor->e_type)
    {
        m_fd =
            STDOUT_FILENO;

        e_status =
            appl_status_ok;
    }
    else if (
        appl_file_type_stderr == p_file_descriptor->e_type)
    {
        m_fd =
            STDERR_FILENO;

        e_status =
            appl_status_ok;
    }
    else if (
        appl_file_type_disk == p_file_descriptor->e_type)
    {
        e_status =
            appl_status_not_implemented;
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // init()

//
//
//
enum appl_status
    appl_file_std_node::cleanup(void)
{
    enum appl_status
        e_status;

    if (
        m_close)
    {
        close(
            m_fd);

        m_fd =
            -1;

        m_close =
            false;
    }

    e_status =
        appl_status_ok;

    return
        e_status;

} // cleanup()

//
//
//
enum appl_status
    appl_file_std_node::v_read(
        unsigned char * const
            p_buf,
        unsigned long int const
            i_buf_len,
        unsigned long int * const
            r_actual_len)
{
    enum appl_status
        e_status;

    signed long int
        i_read_result;

    i_read_result =
        read(
            m_fd,
            reinterpret_cast<char *>(
                p_buf),
            i_buf_len);

    if (
        i_read_result > 0)
    {
        *(
            r_actual_len) =
            static_cast<unsigned long int>(
                i_read_result);

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

} // v_read()

//
//
//
enum appl_status
    appl_file_std_node::v_write(
        unsigned char const * const
            p_buf,
        unsigned long int const
            i_buf_len,
        unsigned long int * const
            r_actual_len)
{
    enum appl_status
        e_status;

    signed long int
        i_write_result;

    i_write_result =
        static_cast<signed long int>(
            write(
                m_fd,
                reinterpret_cast<char const *>(
                    p_buf),
                i_buf_len));

    if (
        0 < i_write_result)
    {
        *(
            r_actual_len) =
            static_cast<unsigned long int>(
                i_write_result);

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

} // v_write()

/* end-of-file: appl_file_std_node.cpp */
