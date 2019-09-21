/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_service_h
{
    inc_appl_thread_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_thread;

struct appl_thread_property;

struct appl_thread_descriptor;

struct appl_context;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_thread_service;

//
//
//
class appl_thread_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_thread_descriptor const * const
                p_thread_descriptor,
            struct appl_thread * * const
                r_thread);

        static
        enum appl_status
        s_destroy(
            struct appl_thread * const
                p_thread);

        static
        struct appl_object *
        s_convert(
            struct appl_thread * const
                p_thread);

        static
        struct appl_object const *
        s_convert(
            struct appl_thread const * const
                p_thread);

        static
        enum appl_status
        s_interrupt(
            struct appl_thread * const
                p_thread);

}; // class appl_thread_service

/* end-of-file: appl_thread_service.h */
