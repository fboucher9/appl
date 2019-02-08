/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_url_handle.h>

#include <url/appl_url_service.h>

//
//  Function: appl_url_create()
//
//  Description:
//      Create an empty appl_url object.
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
//      -   Use appl_url_destroy to free memory for appl_url object.
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_create(
        struct appl_context * const
            p_context,
        struct appl_url * * const
            r_url)
{
    return
        appl_url_service::s_create(
            p_context,
            r_url);

} // appl_url_create()

//
//  Function: appl_url_destroy()
//
//  Description:
//      Destroy appl_url object created by appl_url_create() function.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//
//  Returns: Status code.
//
//  Comments:
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_destroy(
        struct appl_url * const
            p_url)
{
    return
        appl_url_service::s_destroy(
            p_url);

} // appl_url_destroy()

//
//  Function: appl_url_decoder()
//
//  Description:
//      Decode of URL, and populate members of appl_url object.
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
//      -   With current implementation, all input bytes are processed so
//          the returned number of bytes should always be equal to total
//          length of input URL.
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_decoder(
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
        appl_url_service::s_decoder(
            p_url,
            p_input_min,
            p_input_max,
            r_input_count);

} // appl_url_decoder()

//
//  Function: appl_url_encoder()
//
//  Description:
//      Encode an URL using members of appl_url object.
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
//      -   It is important to use the returned count since the output URL
//          is not zero-terminated.  The returned count is the only way to
//          determine the length of the output URL.
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_encoder(
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
        appl_url_service::s_encoder(
            p_url,
            p_output_min,
            p_output_max,
            r_output_count);

} // appl_url_encoder()

//
//  Function: appl_url_add_component()
//
//  Description:
//      Add a component of given type at end of linked list.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//      e_component_type
//          Type of component to add.
//      p_buf_min
//          Pointer to left bound of component text.
//      p_buf_max
//          Pointer to right bound of component text.
//      r_handle
//          Returned private handle associated with added component.
//
//  Returns: Status code.
//
//  Comments:
//      -   The returned handle may be used with the appl_url_remove_component
//          function to undo the appl_url_add_component operation.
//      -   If the returned handle is lost it may be found using the
//          appl_url_get_component and appl_url_next_component functions.
//      -   Adding more than one component for a given type is only supported
//          for the userinfo and path components.  All other types will
//          return an error at second add.
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_add_component(
        struct appl_url * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * const
            p_buf_min,
        unsigned char const * const
            p_buf_max,
        void * * const
            r_handle)
{
    return
        appl_url_service::s_add_component(
            p_url,
            e_component_type,
            p_buf_min,
            p_buf_max,
            r_handle);

} // appl_url_add_component()

//
//  Function: appl_url_remove_component()
//
//  Description:
//      Remove a component of given type from linked list.  The component to
//      remove is identified by its type and by an opaque handle.  The opaque
//      handle is returned by appl_url_add_component, appl_url_get_component
//      or by appl_url_next_component.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//      e_component_type
//          Type of component to remove.
//      p_handle
//          Handle of component to remove.
//
//  Returns: Status code.
//
//  Comments:
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_remove_component(
        struct appl_url * const
            p_url,
        signed short int const
            e_component_type,
        void * const
            p_handle)
{
    return
        appl_url_service::s_remove_component(
            p_url,
            e_component_type,
            p_handle);

} // appl_url_remove_component()

//
//  Function: appl_url_get_component()
//
//  Description:
//      Get first component of given type from linked list.
//
//  Parameters:
//      p_url
//          Pointer to appl_url object.
//      e_component_type
//          Type of component to get.
//      r_buf_min
//          Returned left bound of component text.
//      r_buf_max
//          Returned right bound of component text.
//      r_handle
//          Returned handle of first component.
//
//  Returns: Status code.
//
//  Comments:
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_get_component(
        struct appl_url const * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle)
{
    return
        appl_url_service::s_get_component(
            p_url,
            e_component_type,
            r_buf_min,
            r_buf_max,
            r_handle);

} // appl_url_get_component()

//
//  Function: appl_url_next_component()
//
//  Description:
//
//  Parameters:
//
//  Returns: Status code.
//
//  Comments:
//      -   This is a C entry point, dispatch to a C++ function.
//
enum appl_status
    appl_url_next_component(
        struct appl_url const * const
            p_url,
        signed short int const
            e_component_type,
        unsigned char const * * const
            r_buf_min,
        unsigned char const * * const
            r_buf_max,
        void * * const
            r_handle)
{
    return
        appl_url_service::s_next_component(
            p_url,
            e_component_type,
            r_buf_min,
            r_buf_max,
            r_handle);

} // appl_url_next_component()

//
//
//
enum appl_status
    appl_url_get_flags(
        struct appl_url const * const
            p_url,
        unsigned long int * const
            r_flags)
{
    return
        appl_url_service::s_get_flags(
            p_url,
            r_flags);

} // appl_url_get_flags()

//
//
//
enum appl_status
    appl_url_set_flags(
        struct appl_url * const
            p_url,
        unsigned long int const
            i_flags)
{
    return
        appl_url_service::s_set_flags(
            p_url,
            i_flags);

} // appl_url_set_flags

/* end-of-file: appl_url_handle.cpp */
