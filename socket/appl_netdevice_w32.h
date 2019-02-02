/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netdevice_w32_h
{
    inc_appl_netdevice_w32_h = 1
        /* Header file dependencies */
        + inc_appl_status_h

}; /* enum guard_appl_netdevice_w32_h */

/* Included. */
#define INC_APPL_NETDEVICE_W32_H

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_context;

struct appl_netdevice_descriptor;

//
//
//
class appl_netdevice_w32
{
    public:

        static
        enum appl_status
            s_enumerate(
                struct appl_context * const
                    p_context,
                struct appl_netdevice_descriptor const * const
                    p_netdevice_filter,
                void (* p_callback)(
                    void * const
                        p_callback_context,
                    struct appl_netdevice_descriptor const * const
                        p_netdevice_descriptor),
                void * p_callback_context);

}; // class appl_netdevice_w32

/* end-of-file: appl_netdevice_w32.h */
