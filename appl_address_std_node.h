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

class appl_socket_std_node;

class appl_socket_w32_node;

//
//
//
class appl_address_std_node : public appl_address
{
    friend class appl_socket_std_node;
    friend class appl_socket_w32_node;

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

        union appl_address_std_node_storage
        {
            struct sockaddr_storage
                o_sockaddr_storage;

            struct sockaddr_in
                o_sockaddr_in;

        } m_sockaddr;

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

        enum appl_status
            init(
                struct appl_address_property const * const
                    p_property);

        virtual
        enum appl_status
            v_get_name_len(
                unsigned long int * const
                    r_name_len) const;

        virtual
        enum appl_status
            v_get_name(
                unsigned char * const
                    p_name_min,
                unsigned char * const
                    p_name_max,
                unsigned char * * const
                    r_name_cur) const;

        virtual
        enum appl_status
            v_get_port(
                unsigned short int * const
                    r_port) const;

}; // class appl_address_std_node

/* end-of-file: appl_address_std_node.h */
