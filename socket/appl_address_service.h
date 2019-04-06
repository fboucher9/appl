/* See LICENSE for license details */

/*

Module: appl_address_service.h

Description:
    Services for handling of address handles.

*/

/* Reverse include guard */
enum guard_appl_address_service_h
{
    inc_appl_address_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_address_property;

/* Predefine */
struct appl_address_descriptor;

/* Predefine */
struct appl_address;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_address_service;

//
//  Class: appl_address_service
//
//  Description:
//      Collection of static methods that allow to interface with address
//      handles.
//
class appl_address_service
{
    public:

        // Create an address handle
        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_address_property const * const
                p_address_descriptor,
            struct appl_address * * const
                r_address);

        static
        enum appl_status
        s_destroy(
            struct appl_address * const
                p_address);

        static
        struct appl_object *
        s_parent(
            struct appl_address * const
                p_address);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_address const * const
                p_address);

        // Get length of address
        static
        enum appl_status
        s_get_name_len(
            struct appl_address const * const
                p_address,
            unsigned long int * const
                r_name_len);

        // Get name of address
        static
        enum appl_status
        s_get_name(
            struct appl_address const * const
                p_address,
            unsigned char * const
                p_name_min,
            unsigned char * const
                p_name_max,
            unsigned char * * const
                r_name_cur);

        // Get port number
        static
        enum appl_status
        s_get_port(
            struct appl_address const * const
                p_address,
            unsigned short int * const
                r_port);

        // Get family
        static
        enum appl_status
        s_get_family(
            struct appl_address const * const
                p_address,
            int * const
                r_family);

        // Get index
        static
        enum appl_status
        s_get_index(
            struct appl_address const * const
                p_address,
            unsigned int * const
                r_index);

        // Name resolution
        static
        enum appl_status
        s_resolve(
            struct appl_context * const
                p_context,
            struct appl_address_descriptor const * const
                p_address_descriptor,
            void (* p_callback)(
                void * const
                    p_callback_context,
                struct appl_address_descriptor const * const
                    p_address_descriptor),
            void * const
                p_callback_context);

}; // class appl_address_service

/* end-of-file: appl_address_service.h */
