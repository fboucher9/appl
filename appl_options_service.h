/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_OPTIONS_SERVICE_H
#error include appl_options_service.h once
#endif /* #if defined INC_APPL_OPTIONS_SERVICE_H */

#define INC_APPL_OPTIONS_SERVICE_H

struct appl_object;

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
        s_create(
            struct appl_context * const
                p_context,
            struct appl_options * * const
                r_instance);

        static
        struct appl_object *
        s_parent(
            struct appl_options * const
                p_options);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_options const * const
                p_options);

        static
        enum appl_status
        s_count(
            struct appl_options const * const
                p_options,
            unsigned long int * const
                r_count);

        static
        enum appl_status
        s_get(
            struct appl_options const * const
                p_options,
            unsigned long int const
                i_index,
            unsigned char const * * const
                r_buf_min,
            unsigned char const * * const
                r_buf_max);

        static
        enum appl_status
        s_write(
            struct appl_options * const
                p_options,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                p_count,
            char * const
                p_ready);

        static
        enum appl_status
        s_append_argument(
            struct appl_options * const
                p_options,
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max);

}; // appl_options_service

/* end-of-file: appl_options_service.h */
