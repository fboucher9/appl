/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_POLL_SERVICE_H
#error include appl_poll_service.h once
#endif /* #if defined INC_APPL_POLL_SERVICE_H */

#define INC_APPL_POLL_SERVICE_H

struct appl_context_handle;

struct appl_poll_descriptor;

struct appl_poll_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_poll_service;

//
//
//
class appl_poll_service
{
    public:

        static
        enum appl_status
        create_handle(
            struct appl_context_handle * const
                p_context_handle,
            struct appl_poll_descriptor const * const
                p_poll_descriptor,
            struct appl_poll_handle * * const
                r_poll_handle);

}; // class appl_poll_service

/* end-of-file: appl_poll_service.h */
