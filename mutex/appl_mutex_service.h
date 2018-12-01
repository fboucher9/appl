/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_mutex_service_h
{
    inc_appl_mutex_service_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_context;

struct appl_mutex_descriptor;

struct appl_mutex;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_mutex_service;

//
//
//
class appl_mutex_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_mutex_descriptor const * const
                    p_mutex_descriptor,
                struct appl_mutex * * const
                    r_mutex);

        static
        enum appl_status
            s_destroy(
                struct appl_mutex * const
                    p_mutex);

        static
        enum appl_status
            s_lock(
                struct appl_mutex * const
                    p_mutex);

        static
        enum appl_status
            s_unlock(
                struct appl_mutex * const
                    p_mutex);

        static
        enum appl_status
            s_sync(
                struct appl_mutex * const
                    p_mutex,
                enum appl_status (*
                    p_sync_callback)(
                    void * const
                        p_sync_context),
                void * const
                    p_sync_context);

}; // class appl_mutex_service

/* end-of-file: appl_mutex_service.h */
