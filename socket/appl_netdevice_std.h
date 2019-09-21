/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netdevice_std_h
{
    inc_appl_netdevice_std_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_netdevice_mgr_h

}; /* enum guard_appl_netdevice_std_h */

/* Included. */
#define INC_APPL_NETDEVICE_STD_H

/* Assert compiler */
#include <appl_assert_cplusplus.h>

/* Assert configuration */
#include <appl_assert_linux.h>

struct appl_netdevice_descriptor;

//
//
//
class appl_netdevice_std : public appl_netdevice_mgr
{
    public:

        appl_netdevice_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_netdevice_std();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        appl_netdevice_std(
            class appl_netdevice_std const & r);

        class appl_netdevice_std &
            operator =(
                class appl_netdevice_std const & r);

        virtual
        enum appl_status
            v_enumerate(
                struct appl_netdevice_descriptor const * const
                    p_netdevice_filter,
                void (* p_callback)(
                    void * const
                        p_callback_context,
                    struct appl_netdevice_descriptor const * const
                        p_netdevice_descriptor),
                void * p_callback_context);

}; // class appl_netdevice_std

/* end-of-file: appl_netdevice_std.h */
