/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_MUTEX_SERVICE_H
#error include appl_mutex_service.h once
#endif /* #if defined INC_APPL_MUTEX_SERVICE_H */

#define INC_APPL_MUTEX_SERVICE_H

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
            s_lock(
                struct appl_mutex * const
                    p_mutex);

        static
        enum appl_status
            s_unlock(
                struct appl_mutex * const
                    p_mutex);

}; // class appl_mutex_service

/* end-of-file: appl_mutex_service.h */
