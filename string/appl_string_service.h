/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_string_service_h
{
    inc_appl_string_service_h =
        /* Header file dependency */
        inc_appl_status_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_string_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context const * const
                p_context,
            unsigned long int const
                i_alloc_len,
            struct appl_string * * const
                r_string);

        static
        enum appl_status
        s_destroy(
            struct appl_string * const
                p_string);

        static
        struct appl_object *
        s_parent(
            struct appl_string * const
                p_string);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_string const * const
                p_string);

        static
        enum appl_status
        s_length(
            struct appl_string const * const
                p_string,
            unsigned long int * const
                r_length);

        static
        enum appl_status
        s_get(
            struct appl_string const * const
                p_string,
            unsigned char * * const
                r_buf_min,
            unsigned char * * const
                r_buf_max);

}; // class appl_string_service

/* end-of-file: appl_string_service.h */
