/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_std_node_h
{
    inc_appl_socket_std_node_h =
        /* Header file dependency */
        inc_appl_socket_node_h
};

struct appl_object;

struct appl_socket_property;

struct appl_socket;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_socket_std_mgr;

class appl_socket_std_node;

//
//
//
class appl_socket_std_node : public appl_socket
{
    friend class appl_socket_std_mgr;

    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                struct appl_socket_property const * const
                    p_socket_descriptor,
                struct appl_socket * * const
                    r_socket);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                struct appl_socket * const
                    p_socket);

        appl_socket_std_node(
            struct appl_context * const
                p_context);

        virtual
        ~appl_socket_std_node();

        enum appl_status
            f_init(
                struct appl_socket_property const * const
                    p_socket_descriptor);

        enum appl_status
            f_init(
                int const * const
                    p_socket_descriptor);

    protected:

    private:

        int
            m_fd;

#define PADDING (APPL_SIZEOF_INT)
#include <appl_padding.h>

        appl_socket_std_node(
            class appl_socket_std_node const & r);

        class appl_socket_std_node &
            operator =(
                class appl_socket_std_node const & r);

        enum appl_status
        init_socket(
            struct appl_socket_property const * const
                p_socket_descriptor);

        enum appl_status
        init_bind(
            struct appl_socket_property const * const
                p_socket_descriptor);

        enum appl_status
        init_connect(
            struct appl_socket_property const * const
                p_socket_descriptor);

        enum appl_status
        init_listen(
            struct appl_socket_property const * const
                p_socket_descriptor);

        enum appl_status
        init_recv_timeout(
            struct appl_socket_property const * const
                p_socket_descriptor);

        enum appl_status
        init_send_timeout(
            struct appl_socket_property const * const
                p_socket_descriptor);

        virtual
        appl_size_t
        v_cleanup(void);

        virtual
        enum appl_status
        v_accept(
            struct appl_socket * * const
                r_socket,
            struct appl_address * * const
                r_address);

        virtual
        enum appl_status
        v_send(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count);

        virtual
        enum appl_status
        v_recv(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count);

        virtual
        enum appl_status
        v_sendto(
            unsigned char const * const
                p_buf_min,
            unsigned char const * const
                p_buf_max,
            unsigned long int * const
                r_count,
            struct appl_address * const
                p_remote_address);

        virtual
        enum appl_status
        v_recvfrom(
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max,
            unsigned long int * const
                r_count,
            struct appl_address * const
                p_remote_address);

}; // class appl_socket_std_node

/* end-of-file: appl_socket_std_node.h */
