/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <module/appl_packet.h>

//
//
//
appl_packet::appl_packet(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    p_module(),
    p_buf_min(),
    p_buf_max(),
    e_type()
{
}

//
//
//
appl_packet::~appl_packet()
{
}

//
//
//
enum appl_status
    appl_packet::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_packet::v_cleanup(void)
{
    return
        sizeof(struct appl_packet);

} // v_cleanup()

/* end-of-file: appl_packet.cpp */
