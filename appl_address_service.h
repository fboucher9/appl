/* See LICENSE for license details */

/*

Module: appl_address_service.h

Description:
    Services for handling of address handles.

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_SERVICE_H
#error include appl_address_service.h once
#endif /* #if defined INC_APPL_ADDRESS_SERVICE_H */

#define INC_APPL_ADDRESS_SERVICE_H

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_address_property;

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

}; // class appl_address_service

/* end-of-file: appl_address_service.h */
