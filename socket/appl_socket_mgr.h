/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_mgr_h
{
    inc_appl_socket_mgr_h =
        /* Header file dependencies */
        inc_appl_object_h
};

struct appl_address_property;

struct appl_socket_property;

struct appl_poll_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_socket_mgr;

//
//
//
class appl_socket_mgr : public appl_object
{
    public:

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

    protected:

        appl_socket_mgr();

        virtual
        ~appl_socket_mgr();

    private:

        appl_socket_mgr(
            class appl_socket_mgr const & r);

        class appl_socket_mgr &
            operator =(
                class appl_socket_mgr const & r);

}; // class appl_socket_mgr

/* end-of-file: appl_socket_mgr.h */
