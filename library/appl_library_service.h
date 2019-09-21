/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_library_service_h
{
    inc_appl_library_service_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_context;

struct appl_library_descriptor;

struct appl_library;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_library_service;

//
//
//
class appl_library_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_library_descriptor const * const
                    p_library_descriptor,
                struct appl_library * * const
                    r_library);

        static
        enum appl_status
            s_destroy(
                struct appl_library * const
                    p_library);

        static
        struct appl_object *
            s_parent(
                struct appl_library * const
                    p_library);

        static
        struct appl_object const *
            s_const_parent(
                struct appl_library const * const
                    p_library);

        static
        enum appl_status
            s_query(
                struct appl_library const * const
                    p_library,
                unsigned char const * const
                    p_symbol_name_min,
                unsigned char const * const
                    p_symbol_name_max,
                void * * const
                    r_symbol);

}; // class appl_library_service

/* end-of-file: appl_library_service.h */
