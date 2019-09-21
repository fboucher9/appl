/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_netdevice_service_h
{
    inc_appl_netdevice_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h

}; /* enum guard_appl_netdevice_service_h */

/* Included. */
#define INC_APPL_NETDEVICE_SERVICE_H

/* Assert compiler */
#include <appl_assert_cplusplus.h>

struct appl_context;

struct appl_netdevice_descriptor;

//
//
//
class appl_netdevice_service
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

}; // class appl_netdevice_service

/* end-of-file: appl_netdevice_service.h */
