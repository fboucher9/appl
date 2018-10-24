/* See LICENSE for license details */

/*

*/

#include <unistd.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_file_node.h>

#include <appl_file_std_node.h>

#include <appl_buf.h>

#include <appl_file_descriptor.h>

#include <appl_buf0.h>

#include <appl_convert.h>

#include <appl_allocator.h>

struct appl_file_std_node_descriptor
{
    struct appl_file_descriptor const *
        p_file_descriptor;

}; /* struct appl_file_std_node_descriptor */

//
//
//
enum appl_status
    appl_file_std_node::s_create(
        struct appl_allocator * const
            p_allocator,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    struct appl_file_std_node_descriptor
        o_file_std_node_descriptor;

    o_file_std_node_descriptor.p_file_descriptor =
        p_file_descriptor;

    class appl_file_std_node *
        p_file_std_node;

    e_status =
        p_allocator->alloc_object(
            &(
                o_file_std_node_descriptor),
            &(
                p_file_std_node));

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_file) =
            p_file_std_node;
    }

    return
        e_status;

} // create_instance()

//
//
//
appl_file_std_node::appl_file_std_node() :
    appl_file(),
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
enum appl_status
    appl_file_std_node::f_init(
        struct appl_file_std_node_descriptor const * const
            p_file_std_node_descriptor)
{
    enum appl_status
        e_status;

    struct appl_file_descriptor const * const
        p_file_descriptor =
        p_file_std_node_descriptor->p_file_descriptor;

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
        unsigned char *
            a_pathname;

        e_status =
            appl_buf0_create(
                this,
                p_file_descriptor->p_name_min,
                p_file_descriptor->p_name_max,
                &(
                    a_pathname));

        if (
            appl_status_ok
            == e_status)
        {
            memcpy(
                a_pathname,
                p_file_descriptor->p_name_min,
                appl_buf_len(
                    p_file_descriptor->p_name_min,
                    p_file_descriptor->p_name_max));

            *(
                a_pathname
                + (p_file_descriptor->p_name_max
                    - p_file_descriptor->p_name_min)) =
                '\000';

            int
                i_flags;

            if (
                appl_file_mode_read == p_file_descriptor->e_mode)
            {
                i_flags =
                    0;
            }
            else if (
                appl_file_mode_write == p_file_descriptor->e_mode)
            {
                i_flags =
                    O_CREAT | O_TRUNC;
            }
            else if (
                appl_file_mode_modify == p_file_descriptor->e_mode)
            {
                i_flags =
                    O_CREAT;
            }
            else if (
                appl_file_mode_append == p_file_descriptor->e_mode)
            {
                i_flags =
                    O_APPEND;
            }
            else
            {
                i_flags =
                    0;
            }

            int
                i_mode;

#if defined APPL_OS_LINUX
            i_mode =
                S_IRUSR
                | S_IWUSR
                | S_IRGRP
                | S_IWGRP
                | S_IROTH;
#else /* #if defined APPL_OS_LINUX */
            i_mode =
                0664;
#endif /* #if defined APPL_OS_LINUX */

            m_fd =
                open(
                    appl_convert::to_char_ptr(
                        a_pathname),
                    i_flags,
                    i_mode);

            if (
                m_fd >= 0)
            {
                e_status =
                    appl_status_ok;
            }
            else
            {
                e_status =
                    appl_status_fail;
            }

            appl_buf0_destroy(
                this,
                a_pathname);
        }
    }
    else
    {
        e_status =
            appl_status_fail;
    }

    return
        e_status;

} // f_init()

//
//
//
enum appl_status
    appl_file_std_node::v_cleanup(void)
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

    // Free ourselves using mgr pool...
    e_status =
        appl_status_ok;

    return
        e_status;

} // v_cleanup()

//
//
//
enum appl_status
    appl_file_std_node::v_read(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    signed long int
        i_read_result;

    i_read_result =
        read(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max));

    if (
        i_read_result > 0)
    {
        *(r_count) =
            appl_convert::to_unsigned(
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
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    signed long int
        i_write_result;

    i_write_result =
        write(
            m_fd,
            p_buf_min,
            appl_buf_len(
                p_buf_min,
                p_buf_max));

    if (
        0 < i_write_result)
    {
        *(r_count) =
            appl_convert::to_unsigned(
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
