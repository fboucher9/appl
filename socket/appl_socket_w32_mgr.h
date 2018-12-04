/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_socket_w32_mgr_h
{
    inc_appl_socket_w32_mgr_h =
        /* Header file dependency */
        inc_appl_socket_mgr_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_socket_w32_mgr;

//
//
//
class appl_socket_w32_mgr : public appl_socket_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_socket_mgr * * const
                    r_socket_mgr);

        appl_socket_w32_mgr();

        virtual
        ~appl_socket_w32_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_socket_w32_mgr(
            class appl_socket_w32_mgr const & r);

        class appl_socket_w32_mgr &
            operator =(
                class appl_socket_w32_mgr const & r);

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
            v_create_socket(
                struct appl_socket_property const * const
                    p_socket_descriptor,
                struct appl_socket * * const
                    r_socket_node);

}; // class appl_socket_w32_mgr

/* end-of-file: appl_socket_w32_mgr.h */
