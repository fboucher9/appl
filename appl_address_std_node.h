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

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_context;

struct appl_property;

class appl_address_std_node;

//
//
//
class appl_address_std_node : public appl_address
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_address_property const * const
                    p_property,
                struct appl_address * * const
                    r_address);

    protected:

        appl_address_std_node();

        virtual
        ~appl_address_std_node();

    private:

        struct sockaddr_storage
            m_sockaddr_storage;

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

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

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

}; // class appl_address_std_node

/* end-of-file: appl_address_std_node.h */
