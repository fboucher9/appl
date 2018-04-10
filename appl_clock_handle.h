/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CLOCK_HANDLE_H
#error include appl_clock_handle.h once
#endif /* #if defined INC_APPL_CLOCK_HANDLE_H */

#define INC_APPL_CLOCK_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_object_handle;

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

enum appl_status
appl_clock_read(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int * const
        p_time_count);

enum appl_status
appl_clock_delay(
    struct appl_object_handle const * const
        p_object_handle,
    unsigned long int const
        i_time_freq,
    unsigned long int const
        i_time_count);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_clock_handle.h */
