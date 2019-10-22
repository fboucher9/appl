/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_predefines.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <unique/appl_unique.h>

//
//
//
appl_unique::appl_unique(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context),
    m_value()
{
}

//
//
//
appl_unique::~appl_unique()
{
}

//
//
//
enum appl_status
    appl_unique::f_init(
        struct appl_unique_descriptor const * const
            p_descriptor)
{
    m_value =
        p_descriptor->i_value;

    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_unique::v_cleanup(void)
{
    return
        sizeof(
            struct appl_unique);

} // v_cleanup()

//
//
//
unsigned long int
    appl_unique::f_get(void) const
{
    return
        m_value;

} // f_get()

