/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_types.h>

#include <appl_object.h>

#include <url/appl_url.h>

#include <url/appl_url_std.h>

#include <appl_unused.h>

//
//
//
appl_url_std::appl_url_std(
    struct appl_context * const
        p_context) :
    appl_url(
        p_context)
{
}

//
//
//
appl_url_std::~appl_url_std()
{
}

//
//
//
enum appl_status
    appl_url_std::f_init(void)
{
    return
        appl_status_ok;

} // f_init()

//
//
//
appl_size_t
    appl_url_std::v_cleanup(void)
{
    return
        sizeof(class appl_url_std);

} // v_cleanup()

//
//
//
enum appl_status
    appl_url_std::v_decoder(
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
//
//
enum appl_status
    appl_url_std::v_encoder(
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
//
//
enum appl_status
    appl_url_std::v_add_component(
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
    appl_url_std::v_remove_component(
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
    appl_url_std::v_get_component(
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
    appl_url_std::v_next_component(
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
    appl_url_std::v_get_flags(
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
    appl_url_std::v_set_flags(
        unsigned long int const
            i_flags)
{
    appl_unused(
        i_flags);

    return
        appl_raise_not_implemented();

} // v_set_flags()

/* end-of-file: appl_url_std.cpp */
