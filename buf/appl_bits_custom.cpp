/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <buf/appl_bits.h>

#include <buf/appl_buf.h>

#include <buf/appl_bits_descriptor.h>

#include <buf/appl_bits_base.h>

#include <buf/appl_bits_custom.h>

#include <misc/appl_unused.h>

#include <misc/appl_convert.h>

//
//
//
appl_bits_custom::appl_bits_custom(
    struct appl_context * const
        p_context) :
    appl_bits_base(
        p_context),
    m_descriptor()
{
}

//
//
//
appl_bits_custom::~appl_bits_custom()
{
}

//
//
//
enum appl_status
appl_bits_custom::f_init(
    struct appl_bits_custom_descriptor const * const
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
appl_bits_custom::v_cleanup(void)
{
    return
        sizeof(class appl_bits_custom);

} // v_cleanup()

//
//
//
enum appl_status
appl_bits_custom::v_consume(
    unsigned char * const
        r_value)
{
    enum appl_status
        e_status;

    // Load bytes from input buffer
    e_status =
        (*(m_descriptor.p_callback_consume))(
            m_descriptor.p_callback_context,
            r_value);

    return
        e_status;

} // v_read()

//
//
//
enum appl_status
appl_bits_custom::v_produce(
    unsigned char const
        i_value)
{
    enum appl_status
        e_status;

    e_status =
        (*(m_descriptor.p_callback_produce))(
            m_descriptor.p_callback_context,
            i_value);

    return
        e_status;

} // v_write()

/* end-of-file: appl_bits_custom.cpp */
