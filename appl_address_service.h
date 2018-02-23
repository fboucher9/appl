/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_SERVICE_H
#error include appl_address_service.h once
#endif /* #if defined INC_APPL_ADDRESS_SERVICE_H */

#define INC_APPL_ADDRESS_SERVICE_H

struct appl_context_handle;

struct appl_address_descriptor;

struct appl_address_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_address_service;

//
//
//
class appl_address_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context_handle * const
                p_context_handle,
            struct appl_address_descriptor const * const
                p_address_descriptor,
            struct appl_address_handle * * const
                r_address_handle);

}; // class appl_address_service

/* end-of-file: appl_address_service.h */
