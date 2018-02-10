/* See LICENSE for license details */

/*

Module: appl_file_node.cpp

Description:

    Interface of file object.

*/

#include "appl_status.h"

#include "appl_types.h"

#include "appl_object.h"

#include "appl_file_node.h"

//
//
//
enum appl_status
    appl_file_node::v_read(
        unsigned char * const
            p_buf,
        unsigned long int const
            i_buf_len,
        unsigned long int * const
            r_actual_len)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);
    static_cast<void>(
        r_actual_len);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
    appl_file_node::v_write(
        unsigned char const * const
            p_buf,
        unsigned long int const
            i_buf_len,
        unsigned long int * const
            r_actual_len)
{
    enum appl_status
        e_status;

    static_cast<void>(
        p_buf);
    static_cast<void>(
        i_buf_len);
    static_cast<void>(
        r_actual_len);

    e_status =
        appl_status_not_implemented;

    return
        e_status;

} // v_write()

//
//
//
class appl_file_node *
    appl_file_node::convert_handle(
        struct appl_file_handle * const
            p_file_handle)
{
    return
        reinterpret_cast<class appl_file_node *>(
            p_file_handle);

} // convert_handle()

//
//
//
appl_file_node::appl_file_node() :
    appl_object()
{
}

//
//
//
appl_file_node::~appl_file_node()
{
}

/* end-of-file: appl_file_node.cpp */
