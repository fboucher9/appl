/* See LICENSE for license details */

/*

Module: appl_url_service.cpp

Description:
    C++ thunk for appl_url_handle functions.

*/

#include <appl_status.h>

#include <url/appl_url_types.h>

#include <url/appl_url_service.h>

#include <appl_types.h>

#include <object/appl_object.h>

#include <url/appl_url.h>

#include <list/appl_list.h>

#include <url/appl_url_std.h>

#include <misc/appl_unused.h>

#include <context/appl_context_handle.h>

#include <allocator/appl_allocator_handle.h>

//
//  Function: s_create()
//
//  Description:
//      C++ thunk for appl_url_create().
//
//  Parameters:
//      p_context
//          Pointer to appl_context object.
//      r_url
//          Returned pointer to appl_url object.
//
//  Returns: Status code.
//
//  Comments:
//      -   Use default allocator.
//      -   Create a appl_url_std object.
//
enum appl_status
    appl_url_service::s_create(
        struct appl_context * const
            p_context,
        struct appl_url * * const
            r_url)
{
    enum appl_status
        e_status;

    class appl_url_std *
        p_url_std;

    {
        struct appl_allocator * const
            p_allocator =
            appl_context_get_allocator(
                p_context);

        e_status =
            appl_new(
                p_allocator,
                &(
                    p_url_std));
    }

    if (
        appl_status_ok
        == e_status)
    {
        *(
            r_url) =
            p_url_std;
    }

    return
        e_status;

} // s_create()

//
//  Function: s_destroy()
//
//  Description:
//      C++ thunk for appl_url_destroy().
//
//  Parameters:
//      p_url
//          Pointer to appl_url object to destroy.
//
//  Returns: Status code.
//
//  Comments:
//      -   Use default allocator.
//
enum appl_status
    appl_url_service::s_destroy(
        struct appl_url * const
            p_url)
{
    struct appl_allocator * const
        p_allocator =
        appl_context_get_allocator(
            p_url->get_context());

    return
        appl_delete(
            p_allocator,
            p_url);

} // s_destroy()

//
//  Function: s_decoder()
//
//  Description:
//      C++ thunk for appl_url_decoder() function.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
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
//      -   Dispatch call to appl_url virtual method.
//
enum appl_status
    appl_url_service::s_decoder(
        struct appl_url * const
            p_url,
        unsigned char const * const
            p_input_min,
        unsigned char const * const
            p_input_max,
        unsigned long int * const
            r_input_count)
{
    return
        p_url->v_decoder(
            p_input_min,
            p_input_max,
            r_input_count);

} // s_decoder()

//
//  Function: s_encoder_length()
//
//  Description:
//      C++ thunk for appl_url_encoder_length() function.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//      r_output_count
//          Returned number of bytes for output URL.
//
//  Returns: Status code.
//
//  Comments:
//      -   Dispatch call to appl_url virtual method.
//
enum appl_status
    appl_url_service::s_encoder_length(
        struct appl_url const * const
            p_url,
        unsigned long int * const
            r_output_count)
{
    return
        p_url->v_encoder_length(
            r_output_count);

} // s_encoder_length()

//
//  Function: s_encoder()
//
//  Description:
//      C++ thunk for appl_url_encoder() function.
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
//      -   Dispatch call to appl_url virtual method.
//
enum appl_status
    appl_url_service::s_encoder(
        struct appl_url const * const
            p_url,
        unsigned char * const
            p_output_min,
        unsigned char * const
            p_output_max,
        unsigned long int * const
            r_output_count)
{
    return
        p_url->v_encoder(
            p_output_min,
            p_output_max,
            r_output_count);

} // s_encoder()

//
//  Function: s_add_component()
//
//  Description:
//      C++ thunk for appl_url_add_component() function.
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
//      -   Dispatch call to appl_url virtual method.
//
enum appl_status
    appl_url_service::s_add_component(
        struct appl_url * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        struct appl_url_component * * const
            r_handle)
{
    return
        p_url->v_add_component(
            e_component_type,
            p_buf_min,
            p_buf_max,
            r_handle);

} // s_add_component()

//
//
//
enum appl_status
    appl_url_service::s_remove_component(
        struct appl_url * const
            p_url,
        signed short int const
            e_component_type,
        struct appl_url_component * const
            p_handle)
{
    return
        p_url->v_remove_component(
            e_component_type,
            p_handle);

} // s_remove_component()

//
//
//
enum appl_status
    appl_url_service::s_get_component(
        struct appl_url const * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        struct appl_url_component * * const
            r_handle)
{
    return
        p_url->v_get_component(
            e_component_type,
            r_buf_min,
            r_buf_max,
            r_handle);

} // s_get_component()

//
//
//
enum appl_status
    appl_url_service::s_next_component(
        struct appl_url const * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        struct appl_url_component * * const
            r_handle)
{
    return
        p_url->v_next_component(
            e_component_type,
            r_buf_min,
            r_buf_max,
            r_handle);

} // s_next_component()

//
//
//
enum appl_status
    appl_url_service::s_get_flags(
        struct appl_url const * const
            p_url,
        unsigned long int * const
            r_flags)
{
    return
        p_url->v_get_flags(
            r_flags);

} // s_get_flags()

//
//
//
enum appl_status
    appl_url_service::s_set_flags(
        struct appl_url * const
            p_url,
        unsigned long int const
            i_flags)
{
    return
        p_url->v_set_flags(
            i_flags);

} // s_set_flags()

/* end-of-file: appl_url_service.cpp */
