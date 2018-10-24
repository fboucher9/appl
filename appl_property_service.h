/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_PROPERTY_SERVICE_H
#error include appl_property_service.h once
#endif /* #if defined INC_APPL_PROPERTY_SERVICE_H */

#define INC_APPL_PROPERTY_SERVICE_H

struct appl_context;

struct appl_property;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_property_service;

//
//
//
class appl_property_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            unsigned int const
                i_count,
            struct appl_property * * const
                r_property);

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
