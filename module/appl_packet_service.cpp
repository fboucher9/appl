/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <module/appl_packet_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <module/appl_packet.h>

#include <heap/appl_heap_handle.h>

//
//
//
enum appl_status
appl_packet_service::s_create(
    struct appl_context * const
        p_context,
    struct appl_packet * * const
        r_packet)
{
    enum appl_status
        e_status;

    e_status =
        appl_new(
            p_context,
            r_packet);

    return
        e_status;

} // s_create()

//
//
//
enum appl_status
appl_packet_service::s_destroy(
    struct appl_packet * const
        p_packet)
{
    enum appl_status
        e_status;

    struct appl_context * const
        p_context =
        p_packet->get_context();

    e_status =
        appl_delete(
            p_context,
            p_packet);

    return
        e_status;

} // s_destroy()

//
//
//
struct appl_object *
appl_packet_service::s_parent(
    struct appl_packet * const
        p_packet)
{
    return
        p_packet;

} // s_parent()

//
//
//
struct appl_object const *
appl_packet_service::s_const_parent(
    struct appl_packet const * const
        p_packet)
{
    return
        p_packet;

} // s_const_parent()

//
//
//
enum appl_status
appl_packet_service::s_set_module(
    struct appl_packet * const
        p_packet,
    struct appl_module * const
        p_module)
{
    p_packet->p_module =
        p_module;

    return
        appl_status_ok;

} // s_set_module()

//
//
//
enum appl_status
appl_packet_service::s_set_buffer(
    struct appl_packet * const
        p_packet,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max)
{
    p_packet->p_buf_min =
        p_buf_min;

    p_packet->p_buf_max =
        p_buf_max;

    return
        appl_status_ok;

} // s_set_buffer()

//
//
//
enum appl_status
appl_packet_service::s_set_type(
    struct appl_packet * const
        p_packet,
    unsigned long int const
        e_type)
{
    p_packet->e_type =
        e_type;

    return
        appl_status_ok;

} // s_set_type()

/* end-of-file: appl_packet_service.cpp */
