/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_DICT_SERVICE_H

/* Reverse include guard */
enum guard_appl_dict_service_h
{
    inc_appl_dict_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_dict_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_dict * * const
                r_dict);

        static
        enum appl_status
        s_destroy(
            struct appl_context * const
                p_context,
            struct appl_dict * const
                p_dict);

        static
        struct appl_object *
        s_parent(
            struct appl_dict * const
                p_dict);

        static
        enum appl_status
        s_set(
            struct appl_dict * const
                p_dict,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            void * const
                p_value);

        static
        enum appl_status
        s_get(
            struct appl_dict * const
                p_dict,
            unsigned char const * const
                p_name_min,
            unsigned char const * const
                p_name_max,
            void * * const
                r_value);

}; // class appl_dict_service

/* end-of-file: appl_dict_service.h */
