/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_STD_MGR_H
#error include appl_socket_std_mgr.h once
#endif /* #if defined INC_APPL_SOCKET_STD_MGR_H */

#define INC_APPL_SOCKET_STD_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_SOCKET_MGR_H
#error include appl_socket_mgr.h before
#endif /* #if ! defined INC_APPL_SOCKET_MGR_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

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
                struct appl_object * const
                    p_context,
                class appl_socket_mgr * * const
                    r_socket_mgr);

        static
        void
            s_new(
                void * const
                    p_placement);

    protected:

        appl_socket_std_mgr();

        virtual
        ~appl_socket_std_mgr();

    private:

        appl_socket_std_mgr(
            class appl_socket_std_mgr const & r);

        class appl_socket_std_mgr &
            operator =(
                class appl_socket_std_mgr const & r);

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

}; // class appl_socket_std_mgr

/* end-of-file: appl_socket_std_mgr.h */
