/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <module/appl_packet_handle.h>

#include <module/appl_packet_service.h>

//
//
//
enum appl_status
appl_packet_create(
    struct appl_context * const
        p_context,
    struct appl_packet * * const
        r_packet)
{
    return
        appl_packet_service::s_create(
            p_context,
            r_packet);

} // _create()

//
//
//
enum appl_status
appl_packet_destroy(
    struct appl_packet * const
        p_packet)
{
    return
        appl_packet_service::s_destroy(
            p_packet);

} // _destroy()

//
//
//
struct appl_object *
appl_packet_parent(
    struct appl_packet * const
        p_packet)
{
    return
        appl_packet_service::s_parent(
            p_packet);

} // _parent()

//
//
//
struct appl_object const *
appl_packet_const_parent(
    struct appl_packet const * const
        p_packet)
{
    return
        appl_packet_service::s_const_parent(
            p_packet);

} // _const_parent()

//
//
//
enum appl_status
appl_packet_set_module(
    struct appl_packet * const
        p_packet,
    struct appl_module * const
        p_module)
{
    return
        appl_packet_service::s_set_module(
            p_packet,
            p_module);

} // _set_module()

//
//
//
enum appl_status
appl_packet_set_buffer(
    struct appl_packet * const
        p_packet,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    return
        appl_packet_service::s_set_buffer(
            p_packet,
            p_buf_min,
            p_buf_max);

} // _set_buffer()

//
//
//
enum appl_status
appl_packet_set_type(
    struct appl_packet * const
        p_packet,
    unsigned long int const
        e_type)
{
    return
        appl_packet_service::s_set_type(
            p_packet,
            e_type);

} // _set_type()

/* end-of-file: appl_packet_handle.cpp */
