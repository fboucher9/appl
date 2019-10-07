/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_dir_service_h
{
    inc_appl_dir_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h
        /* ... */
}; /* enum guard_appl_dir_service_h */

/* Predefine descriptor */
struct appl_dir_descriptor;

#include <misc/appl_assert_cplusplus.h>

//
//
//
class appl_dir_service
{
    public:

        static
        enum appl_status
            s_enumerate(
                struct appl_context * const
                    p_context,
                struct appl_dir_descriptor const * const
                    p_descriptor);

}; // class appl_dir_service

/* end-of-file: appl_dir_service.h */
