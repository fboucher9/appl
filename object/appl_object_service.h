/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_object_service_h
{
    inc_appl_object_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_context;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_object_service
{
    public:

        static
        struct appl_context *
        s_get_context(
            struct appl_object const * const
                p_object);

}; // class appl_object_service

/* end-of-file: appl_object_service.h */
