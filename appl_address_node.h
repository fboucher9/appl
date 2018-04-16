/* See LICENSE for license details */

/*

Module: appl_address_node.h

Description:

    Base interface for address objects.

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_NODE_H
#error include appl_address_node.h once
#endif /* #if defined INC_APPL_ADDRESS_NODE_H */

#define INC_APPL_ADDRESS_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Predefine */
struct appl_address;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//  Class: appl_address
//
//  Description:
//      Base interface for address objects.
//
struct appl_address : public appl_object
{
    public:

        virtual
        enum appl_status
            v_get_name(
                unsigned char * * const
                    pp_name_cur,
                unsigned char * const
                    p_name_max) const;

        virtual
        enum appl_status
            v_get_port(
                unsigned short int * const
                    r_port) const;

    protected:

        appl_address();

        virtual
        ~appl_address();

    private:

        appl_address_node(
            struct appl_address const & r);

        struct appl_address &
            operator =(
                struct appl_address const & r);

}; // struct appl_address

/* end-of-file: appl_address_node.h */
