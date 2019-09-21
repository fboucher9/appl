/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_property_service_h
{
    inc_appl_property_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_property_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            unsigned int const
                i_count,
            struct appl_property * * const
                r_property);

        static
        enum appl_status
        s_destroy(
            struct appl_property * const
                p_property);

        static
        enum appl_status
        s_set_ptr(
            struct appl_property * const
                p_property,
            unsigned int const
                i_id,
            void const * const
                p_value);

        static
        enum appl_status
        s_set_ulong(
            struct appl_property * const
                p_property,
            unsigned int const
                i_id,
            unsigned long int const
                u_value);

        static
        enum appl_status
        s_set_long(
            struct appl_property * const
                p_property,
            unsigned int const
                i_id,
            signed long int const
                i_value);

        static
        enum appl_status
        s_get_ptr(
            struct appl_property const * const
                p_property,
            unsigned int const
                i_id,
            void * * const
                r_value);

        static
        enum appl_status
        s_get_ulong(
            struct appl_property const * const
                p_property,
            unsigned int const
                i_id,
            unsigned long int * const
                r_value);

        static
        enum appl_status
        s_get_long(
            struct appl_property const * const
                p_property,
            unsigned int const
                i_id,
            signed long int * const
                r_value);

}; // class appl_property_service

/* end-of-file: appl_property_service.h */
