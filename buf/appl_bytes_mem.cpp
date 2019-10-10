/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <buf/appl_buf.h>

#include <buf/appl_bytes_descriptor.h>

#include <object/appl_object.h>

#include <buf/appl_bytes.h>

#include <buf/appl_bytes_base.h>

#include <buf/appl_bytes_mem.h>

//
//
//
appl_bytes_mem::appl_bytes_mem(
    struct appl_context * const
        p_context) :
    appl_bytes_base(
        p_context),
    m_descriptor(),
    m_iterator()
{
}

//
//
//
appl_bytes_mem::~appl_bytes_mem()
{
}

//
//
//
enum appl_status
    appl_bytes_mem::f_init(
        struct appl_bytes_mem_descriptor const * const
            p_descriptor)
{
    enum appl_status
        e_status;

    m_descriptor =
        *(
            p_descriptor);

    m_iterator =
        p_descriptor->o_buf;

    e_status =
        appl_status_ok;

    return
        e_status;

} // f_init()

//
//
//
appl_size_t
    appl_bytes_mem::v_cleanup(void)
{
    return
        sizeof(
            class appl_bytes_mem);

} // v_cleanup()

//
//
//
enum appl_status
    appl_bytes_mem::v_consume(
        unsigned char * const
            r_value)
{
    enum appl_status
        e_status;

    if (
        m_iterator.o_min.pc_uchar
        < m_iterator.o_max.pc_uchar)
    {
        *(
            r_value) =
            *(
                m_iterator.o_min.pc_uchar);

        m_iterator.o_min.pc_uchar ++;

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

} // v_consume()

//
//
//
enum appl_status
    appl_bytes_mem::v_produce(
        unsigned char const
            i_value)
{
    enum appl_status
        e_status;

    if (
        m_iterator.o_min.p_uchar
        < m_iterator.o_max.p_uchar)
    {
        *(
            m_iterator.o_min.p_uchar) =
            i_value;

        m_iterator.o_min.p_uchar ++;

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

} // v_produce()

/* end-of-file: appl_bytes_mem.cpp */
