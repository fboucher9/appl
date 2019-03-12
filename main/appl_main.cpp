/* See LICENSE for license details */

/*

*/

#include <appl_status.h>

#include <appl_main.h>

#include <main/appl_main_service.h>

/*

*/
int
    appl_main(
        int const
            i_arg_count,
        char * * const
            p_arg_vector,
        enum appl_status (*
            p_main_callback)(
            struct appl_context * const
                p_context,
            struct appl_options const * const
                p_options,
            unsigned long int const
                i_shift))
{
    return
        appl_main_service::s_main(
            i_arg_count,
            p_arg_vector,
            p_main_callback);

} /* appl_main() */

/* end-of-file: appl_main.cpp */
