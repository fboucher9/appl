/* See LICENSE for license details */

/*

Module: appl_file_node.cpp

Description:

    Interface of file object.

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <appl_pool_object.h>

#include <appl_file_node.h>

#include <appl_unused.h>

//
//
//
enum appl_status
    appl_file::v_read(
        unsigned char * const
            p_buf_min,
        unsigned char * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_file::v_write(
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        unsigned long int * const
            r_count)
{
    enum appl_status
        e_status;

    appl_unused(
        p_buf_min,
        p_buf_max,
        r_count);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_write()

//
//
//
appl_file::appl_file() :
    appl_pool_object()
{
}

//
//
//
appl_file::~appl_file()
{
}

/* end-of-file: appl_file_node.cpp */
