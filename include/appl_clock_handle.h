/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_clock_handle_h
{
    inc_appl_clock_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_context;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_clock_read(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t * const
        p_time_count);

enum appl_status
appl_clock_delay(
    struct appl_context const * const
        p_context,
    unsigned long int const
        i_time_freq,
    appl_ull_t const
        i_time_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_clock_handle.h */
