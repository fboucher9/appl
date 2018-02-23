/* See LICENSE for license details */

/*

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

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_address_node;

//
//
//
class appl_address_node : public appl_object
{
    public:

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
