/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_SOCKET_MGR_H
#error include appl_socket_mgr.h once
#endif /* #if defined INC_APPL_SOCKET_MGR_H */

#define INC_APPL_SOCKET_MGR_H

struct appl_address_descriptor;

struct appl_socket_descriptor;

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
                struct appl_address_descriptor const * const
                    p_address_descriptor,
                class appl_address_node * * const
                    r_address_node);

        virtual
        enum appl_status
            v_create_socket(
                struct appl_socket_descriptor const * const
                    p_socket_descriptor,
                class appl_socket_node * * const
                    r_socket_node);

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