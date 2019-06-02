/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_main.h>

#include <main/appl_main_service.h>

/*

*/
void
    appl_main_descriptor_init(
        struct appl_main_descriptor * const
            p_main_descriptor)
{
    appl_main_service::s_init(
        p_main_descriptor);

} /* _init() */

/*

*/
void
    appl_main_descriptor_cleanup(
        struct appl_main_descriptor * const
            p_main_descriptor)
{
    appl_main_service::s_cleanup(
        p_main_descriptor);

} /* _cleanup() */

/*

*/
void
    appl_main_descriptor_set_arg_vector(
        struct appl_main_descriptor * const
            p_main_descriptor,
        char const * const * const
            p_arg_vector_min,
        char const * const * const
            p_arg_vector_max)
{
    appl_main_service::s_set_arg_vector(
        p_main_descriptor,
        p_arg_vector_min,
        p_arg_vector_max);

} /* _set_arg_vector() */

/*

*/
void
    appl_main_descriptor_set_callback(
        struct appl_main_descriptor * const
            p_main_descriptor,
        appl_main_callback * const
            p_main_callback)
{
    appl_main_service::s_set_callback(
        p_main_descriptor,
        p_main_callback);

} /* _set_callback() */

/*

*/
int
    appl_main(
        struct appl_main_descriptor const * const
            p_main_descriptor)
{
    return
        appl_main_service::s_main(
            p_main_descriptor);

} /* appl_main() */

/* end-of-file: appl_main.cpp */
