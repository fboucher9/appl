/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <url/appl_url.h>

#include <appl_unused.h>

//
//  Function: appl_url()
//
//  Description:
//      Duh!
//
//  Parameters:
//      p_context
//          Pointer to appl_context object.
//
//  Returns: None.
//
//  Comments:
//      -   Dispatch parameters to parent class
//
appl_url::appl_url(
    struct appl_context * const
        p_context) :
    appl_object(
        p_context)
{
}

//
//  Function: ~appl_url()
//
//  Description:
//      Duh!
//
//  Parameters:
//      None.
//
//  Returns: None.
//
//  Comments:
//      -   Nothing to cleanup.
//
appl_url::~appl_url()
{
}

//
//  Function: v_decoder()
//
//  Description:
//      Default implementation of v_decoder().
//
//  Parameters:
//      p_input_min
//          Pointer to left bound of input URL.
//      p_input_max
//          Pointer to right bound of input URL.
//      r_input_count
//          Pointer to returned number of bytes.
//
//  Returns: Status code.
//
//  Comments:
//      -   This function should never be called.
//
enum appl_status
    appl_url::v_decoder(
        unsigned char const * const
            p_input_min,
        unsigned char const * const
            p_input_max,
        unsigned long int * const
            r_input_count)
{
    appl_unused(
        p_input_min,
        p_input_max,
        r_input_count);

    return
        appl_raise_not_implemented();

} // v_decoder()

//
//  Function: v_encoder()
//
//  Description:
//      Default implementation of v_encoder().
//
//  Parameters:
//      p_output_min
//          Pointer to left bound of output URL.
//      p_output_max
//          Pointer to right bound of output URL.
//      r_output_count
//          Returned number of bytes written to output URL.
//
//  Returns: Status code.
//
//  Comments:
//      -   This function should never be called.
//
enum appl_status
    appl_url::v_encoder(
        unsigned char * const
            p_output_min,
        unsigned char * const
            p_output_max,
        unsigned long int * const
            r_output_count) const
{
    appl_unused(
        p_output_min,
        p_output_max,
        r_output_count);

    return
        appl_raise_not_implemented();

} // v_encoder()

//
//  Function: v_add_component()
//
//  Description:
//      Default implementation of v_add_component() function.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//      p_output_min
//          Pointer to left bound of output URL.
//      p_output_max
//          Pointer to right bound of output URL.
//      r_output_count
//          Returned number of bytes written to output URL.
//
//  Returns: Status code.
//
//  Comments:
//      -   This function should never be called.
//
enum appl_status
    appl_url::v_add_component(
        signed short int const
            e_component_type,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        void * * const
            r_handle)
{
    appl_unused(
        e_component_type,
        p_buf_min,
        p_buf_max,
        r_handle);

    return
        appl_raise_not_implemented();

} // v_add_component()

//
//
//
enum appl_status
    appl_url::v_remove_component(
        signed short int const
            e_component_type,
        void * const
            p_handle)
{
    appl_unused(
        e_component_type,
        p_handle);

    return
        appl_raise_not_implemented();

} // v_remove_component()

//
//
//
enum appl_status
    appl_url::v_get_component(
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle) const
{
    appl_unused(
        e_component_type,
        r_buf_min,
        r_buf_max,
        r_handle);

    return
        appl_raise_not_implemented();

} // v_get_component()

//
//
//
enum appl_status
    appl_url::v_next_component(
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle) const
{
    appl_unused(
        e_component_type,
        r_buf_min,
        r_buf_max,
        r_handle);

    return
        appl_raise_not_implemented();

} // v_next_component()

//
//
//
enum appl_status
    appl_url::v_get_flags(
        unsigned long int * const
            r_flags) const
{
    appl_unused(
        r_flags);

    return
        appl_raise_not_implemented();

} // v_get_flags()

//
//
//
enum appl_status
    appl_url::v_set_flags(
        unsigned long int const
            i_flags)
{
    appl_unused(
        i_flags);

    return
        appl_raise_not_implemented();

} // v_set_flags()

/* end-of-file: appl_url.cpp */
