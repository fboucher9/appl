/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ADDRESS_STD_NODE_H
#error include appl_address_std_node.h once
#endif /* #if defined INC_APPL_ADDRESS_STD_NODE_H */

#define INC_APPL_ADDRESS_STD_NODE_H

/* Header file dependency */
#if ! defined INC_APPL_ADDRESS_NODE_H
#error include appl_address_node.h before
#endif /* #if ! defined INC_APPL_ADDRESS_NODE_H */

struct appl_address_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_context;

class appl_address_std_node;

//
//
//
class appl_address_std_node : public appl_address_node
{
    public:

        static
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                struct appl_address_descriptor const * const
                    p_address_descriptor,
                class appl_address_node * * const
                    r_address_node);

    protected:

        appl_address_std_node();

        virtual
        ~appl_address_std_node();

    private:

        appl_address_std_node(
            class appl_address_std_node const  & r);

        class appl_address_std_node &
            operator =(
                class appl_address_std_node const  & r);

        static
        void
            s_new(
                void * const
                    p_placement);

}; // class appl_address_std_node

/* end-of-file: appl_address_std_node.h */
