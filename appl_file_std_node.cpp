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

//
//
//
enum appl_status
    appl_file_std_node::create_instance(
        struct appl_context * const
            p_context,
        struct appl_file_descriptor const * const
            p_file_descriptor,
        struct appl_file * * const
            r_file)
{
    enum appl_status
        e_status;

    e_status =
        appl_object::s_create(
            p_context,
            sizeof(
                class appl_file_std_node),
            ( &appl_file_std_node::placement_new ),
            ( &appl_file_std_node::init ),
            p_file_descriptor,
            r_file);

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
        struct appl_file_descriptor const * const
            p_file_descriptor)
{
    enum appl_status
        e_status;

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
        char *
            a_pathname;

        a_pathname =
            static_cast<char *>(
                malloc(
                    static_cast<appl_size_t>(
                        p_file_descriptor->p_name_max
                        - p_file_descriptor->p_name_min)));

        if (
            a_pathname)
        {
            memcpy(
                a_pathname,
                p_file_descriptor->p_name_min,
                static_cast<appl_size_t>(
                    p_file_descriptor->p_name_max
                    - p_file_descriptor->p_name_min));

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
                    a_pathname,
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

            free(
                static_cast<void *>(
                    a_pathname));
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
            static_cast<unsigned int>(
                static_cast<appl_size_t>(
                    p_buf_max
                    - p_buf_min)));

    if (
        i_read_result > 0)
    {
        *(r_count) =
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
        static_cast<signed long int>(
            write(
                m_fd,
                p_buf_min,
                static_cast<unsigned int>(
                    static_cast<appl_size_t>(
                        p_buf_max
                        - p_buf_min))));

    if (
        0 < i_write_result)
    {
        *(r_count) =
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
