/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <buf/appl_bytes.h>

#include <buf/appl_bytes_base.h>

#include <buf/appl_buf.h>

#include <buf/appl_bytes_descriptor.h>

#include <buf/appl_bytes_custom.h>

//
//
//
appl_bytes_custom::appl_bytes_custom(
    struct appl_context * const
        p_context) :
    appl_bytes_base(
        p_context),
    m_descriptor()
{
}

//
//
//
appl_bytes_custom::~appl_bytes_custom()
{
}

//
//
//
enum appl_status
    appl_bytes_custom::f_init(
        struct appl_bytes_custom_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_bytes_custom::v_cleanup(void)
{
    return
        sizeof(class appl_bytes_custom);

} // v_cleanup()

//
//
//
enum appl_status
    appl_bytes_custom::v_consume(
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    e_status =
        (*(m_descriptor.p_consume))(
            m_descriptor.p_void,
            r_value);

    return
        e_status;

} // v_consume()

//
//
//
enum appl_status
    appl_bytes_custom::v_produce(
        unsigned char const
            i_value)
{
    enum appl_status
        e_status;

    e_status =
        (*(m_descriptor.p_produce))(
            m_descriptor.p_void,
            i_value);

    return
        e_status;

} // v_produce()

/* end-of-file: appl_bytes_custom.cpp */
