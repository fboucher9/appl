/* See LICENSE for license details */

/*

*/

#include "appl_status.h"

#include "appl_heap_handle.h"

#include "appl_heap_service.h"

/*

*/
enum appl_status
appl_heap_alloc(
    struct appl_object const * const
        p_object,
    unsigned long int const
        i_length,
    void * * const
        r_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_heap_service::s_alloc(
            p_object,
            i_length,
            r_buf);

    return
        e_status;

} /* appl_heap_alloc() */

/*

*/
enum appl_status
appl_heap_free(
    struct appl_object const * const
        p_object,
    void * const
        p_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_heap_service::s_free(
            p_object,
            p_buf);

    return
        e_status;

} /* appl_heap_free() */

/*

*/
enum appl_status
appl_heap_realloc(
    struct appl_object const * const
        p_object,
    void * const
        p_old_buf,
    unsigned long int const
        i_length,
    void * * const
        r_new_buf)
{
    enum appl_status
        e_status;

    e_status =
        appl_heap_service::s_realloc(
            p_object,
            p_old_buf,
            i_length,
            r_new_buf);

    return
        e_status;

} /* appl_heap_realloc() */

/* end-of-file: appl_heap_handle.cpp */
