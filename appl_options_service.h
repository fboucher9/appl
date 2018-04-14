/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_OPTIONS_SERVICE_H
#error include appl_options_service.h once
#endif /* #if defined INC_APPL_OPTIONS_SERVICE_H */

#define INC_APPL_OPTIONS_SERVICE_H

struct appl_object_handle;

struct appl_string_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_options_service;

//
//
//
class appl_options_service
{
    public:

        static
        enum appl_status
        s_count(
            struct appl_object_handle const * const
                p_object_handle,
            unsigned long int * const
                r_count);

        static
        enum appl_status
        s_get(
            struct appl_object_handle const * const
                p_object_handle,
            unsigned long int const
                i_index,
            unsigned char const * * const
                r_buf_min,
            unsigned char const * * const
                r_buf_max);

}; // appl_options_service

/* end-of-file: appl_options_service.h */
