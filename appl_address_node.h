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
struct appl_address_handle;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_address_node;

//
//  Class: appl_address_node
//
//  Description:
//      Base interface for address objects.
//
class appl_address_node : public appl_object
{
    public:

        static
        class appl_address_node *
        convert_handle(
            struct appl_address_handle * const
                p_address_handle);

        struct appl_address_handle *
        get_handle(void);

        virtual
        enum appl_status
            v_get_name(
                struct appl_buf * const
                    p_name_buf);

        virtual
        enum appl_status
            v_get_port(
                unsigned short int * const
                    r_port);

    protected:

        appl_address_node();

        virtual
        ~appl_address_node();

    private:

        appl_address_node(
            class appl_address_node const & r);

        class appl_address_node &
            operator =(
                class appl_address_node const & r);

}; // class appl_address_node

/* end-of-file: appl_address_node.h */
