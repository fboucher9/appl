/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_address_std_node_h
{
    inc_appl_address_std_node_h =
        /* Header file dependency */
        inc_appl_address_node_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_allocator;

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
                struct appl_allocator * const
                    p_allocator,
                struct appl_address_property const * const
                    p_property,
                struct appl_address * * const
                    r_address);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_address * const
                    p_address);

        appl_address_std_node();

        virtual
        ~appl_address_std_node();

        enum appl_status
            f_init(
                struct appl_address_property const * const
                    p_property);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        union appl_address_std_node_storage
        {
            struct sockaddr_storage
                o_sockaddr_storage;

            struct sockaddr
                o_sockaddr_base;

            struct sockaddr_in
                o_sockaddr_in;

        } m_sockaddr;

        appl_address_std_node(
            class appl_address_std_node const  & r);

        class appl_address_std_node &
            operator =(
                class appl_address_std_node const  & r);

        //
        //
        //
        static
        class appl_address_std_node const *
        convert_handle(
            struct appl_address const * const
                p_address)
        {
            union appl_address_std_node_ptr
            {
                struct appl_address const *
                    p_address;

                class appl_address_std_node const *
                    p_address_std_node;

            } o_address_std_node_ptr;

            o_address_std_node_ptr.p_address =
                p_address;

            return
                o_address_std_node_ptr.p_address_std_node;

        } // convert_handle()

        //
        //
        //
        static
        class appl_address_std_node *
        convert_handle(
            struct appl_address * const
                p_address)
        {
            union appl_address_std_node_ptr
            {
                struct appl_address *
                    p_address;

                class appl_address_std_node *
                    p_address_std_node;

            } o_address_std_node_ptr;

            o_address_std_node_ptr.p_address =
                p_address;

            return
                o_address_std_node_ptr.p_address_std_node;

        } // convert_handle()

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
