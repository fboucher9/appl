/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_std_mgr_h
{
    inc_appl_socket_std_mgr_h =
        /* Header file dependency */
        inc_appl_socket_mgr_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

class appl_socket_std_mgr;

//
//
//
class appl_socket_std_mgr : public appl_socket_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_socket_mgr * * const
                    r_socket_mgr);

        static
        enum appl_status
            s_destroy(
                struct appl_allocator * const
                    p_allocator,
                class appl_socket_mgr * const
                    p_socket_mgr);

        appl_socket_std_mgr(
            struct appl_context * const
                p_context);

        virtual
        ~appl_socket_std_mgr();

    protected:

    private:

        appl_socket_std_mgr(
            class appl_socket_std_mgr const & r);

        class appl_socket_std_mgr &
            operator =(
                class appl_socket_std_mgr const & r);

        virtual
        appl_size_t
            v_cleanup(void);

        virtual
        enum appl_status
            v_create_address(
                struct appl_address_property const * const
                    p_property,
                struct appl_address * * const
                    r_address_node);

        virtual
        enum appl_status
            v_destroy_address(
                struct appl_address * const
                    p_address_node);

        virtual
        enum appl_status
            v_create_socket(
                struct appl_socket_property const * const
                    p_socket_descriptor,
                struct appl_socket * * const
                    r_socket_node);

        virtual
        enum appl_status
            v_destroy_socket(
                struct appl_socket * const
                    p_socket_node);

        virtual
        enum appl_status
            v_poll(
                struct appl_poll_descriptor const * const
                    p_poll_descriptor_min,
                struct appl_poll_descriptor const * const
                    p_poll_descriptor_max,
                unsigned long int const
                    i_wait_freq,
                unsigned long int const
                    i_wait_count);

        virtual
        enum appl_status
            v_resolve(
                struct appl_address_descriptor const * const
                    p_address_descriptor,
                void (* p_callback)(
                    void * const
                        p_callback_context,
                    struct appl_address_descriptor const * const
                        p_address_descriptor),
                void * const
                    p_callback_context);

}; // class appl_socket_std_mgr

/* end-of-file: appl_socket_std_mgr.h */
