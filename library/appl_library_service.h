/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LIBRARY_SERVICE_H
#error include appl_library_service.h once
#endif /* #if defined INC_APPL_LIBRARY_SERVICE_H */

#define INC_APPL_LIBRARY_SERVICE_H

struct appl_context;

struct appl_library_descriptor;

struct appl_library;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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
