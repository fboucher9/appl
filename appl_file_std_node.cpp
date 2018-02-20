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
        char *
            a_pathname;

        a_pathname =
            static_cast<char *>(
                malloc(
                    static_cast<appl_size_t>(
                        p_file_descriptor->o_name.o_max.pc_uchar
                        - p_file_descriptor->o_name.o_min.pc_uchar)));

        if (
            a_pathname)
        {
            memcpy(
                a_pathname,
                p_file_descriptor->o_name.o_min.pc_uchar,
                static_cast<appl_size_t>(
                    p_file_descriptor->o_name.o_max.pc_uchar
                    - p_file_descriptor->o_name.o_min.pc_uchar));

            *(
                a_pathname
                + (p_file_descriptor->o_name.o_max.pc_uchar
                    - p_file_descriptor->o_name.o_min.pc_uchar)) =
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

            i_mode =
                S_IRUSR
                | S_IWUSR
                | S_IRGRP
                | S_IWGRP
                | S_IROTH;

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
        struct appl_buf * const
            p_buf)
{
    enum appl_status
        e_status;

    signed long int
        i_read_result;

    i_read_result =
        read(
            m_fd,
            static_cast<char *>(
                p_buf->o_min.p_void),
            static_cast<unsigned int>(
                static_cast<appl_size_t>(
                    p_buf->o_max.pc_uchar
                    - p_buf->o_min.pc_uchar)));

    if (
        i_read_result > 0)
    {
        p_buf->o_min.pc_uchar +=
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
        struct appl_buf * const
            p_buf)
{
    enum appl_status
        e_status;

    signed long int
        i_write_result;

    i_write_result =
        static_cast<signed long int>(
            write(
                m_fd,
                static_cast<char const *>(
                    p_buf->o_min.pc_void),
                static_cast<unsigned int>(
                    static_cast<appl_size_t>(
                        p_buf->o_max.pc_uchar
                        - p_buf->o_min.pc_uchar))));

    if (
        0 < i_write_result)
    {
        p_buf->o_min.pc_uchar +=
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
