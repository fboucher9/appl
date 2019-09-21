/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_predefines.h>

#include <appl_object.h>

#include <buf/appl_bits.h>

#include <appl_unused.h>

//
//
//
appl_bits::appl_bits(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//
//
appl_bits::~appl_bits()
{
}

//
//
//
enum appl_status
    appl_bits::v_read(
        unsigned char const
            i_count,
        unsigned long int * const
            r_value)
{
    appl_unused(
        i_count,
        r_value);

    return
        appl_raise_not_implemented();

} // v_read()

//
//
//
enum appl_status
    appl_bits::v_write(
        unsigned char const
            i_count,
        unsigned long int const
            i_value)
{
    appl_unused(
        i_count,
        i_value);

    return
        appl_raise_not_implemented();

} // v_write()

/* end-of-file: appl_bits.cpp */
