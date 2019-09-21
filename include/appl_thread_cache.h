/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_thread_cache_h
{
    inc_appl_thread_cache_h =
        /* Header file dependencies */
        inc_appl_status_h
};

struct appl_context;

struct appl_thread_descriptor;

struct appl_thread_cache;

struct appl_thread;

#include <appl_extern_c_begin.h>

enum appl_status
    appl_thread_cache_create(
        struct appl_context * const
            p_context,
        struct appl_thread_descriptor const * const
            p_descriptor,
        struct appl_thread_cache * * const
            r_thread_cache);

enum appl_status
    appl_thread_cache_destroy(
        struct appl_thread_cache * const
            p_thread_cache);

struct appl_thread *
    appl_thread_cache_parent(
        struct appl_thread_cache * const
            p_thread_cache);

#include <appl_extern_c_end.h>

/* end-of-file: appl_thread_cache.h */
