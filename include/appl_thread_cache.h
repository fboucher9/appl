/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_THREAD_CACHE_H
#error include appl_thread_cache.h once
#endif /* #if defined INC_APPL_THREAD_CACHE_H */

#define INC_APPL_THREAD_CACHE_H

struct appl_context;

struct appl_thread_property;

struct appl_thread_descriptor;

struct appl_thread_cache;

struct appl_thread;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
    appl_thread_cache_create(
        struct appl_context * const
            p_context,
        struct appl_thread_property const * const
            p_property,
        struct appl_thread_descriptor const * const
            p_descriptor,
        struct appl_thread_cache * * const
            r_thread_cache);

struct appl_thread *
    appl_thread_cache_parent(
        struct appl_thread_cache * const
            p_thread_cache);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_thread_cache.h */
