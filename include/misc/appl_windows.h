/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_windows_h
{
    inc_appl_windows_h = 1
        /* Header file dependencies */
        | inc_appl_types_h
        /* ... */
}; /* enum guard_appl_windows_h */

#include <misc/appl_extern_c_begin.h>

char
appl_windows_time_begin_period(
    unsigned long int const
        i_period_msec);

char
appl_windows_time_end_period(
    unsigned long int const
        i_period_msec);

char
appl_windows_query_performance_frequency(
    appl_ull_t * const
        r_value);

char
appl_windows_query_performance_counter(
    appl_ull_t * const
        r_value);

char
appl_windows_sleep_ex(
    unsigned long int const
        i_count_msec,
    char const
        b_alertable);

unsigned long int
appl_windows_get_environment_variable(
    char const * const
        lpName,
    char * const
        lpBuffer,
    unsigned long int const
        nSize);

char
appl_windows_set_environment_variable(
    char const * const
        lpName,
    char const * const
        lpValue);

struct appl_windows_critical_section;

struct appl_windows_critical_section *
appl_windows_create_critical_section(void);

void
appl_windows_destroy_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section);

void
appl_windows_enter_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section);

void
appl_windows_leave_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section);

struct appl_windows_condition_variable;

struct appl_windows_condition_variable *
appl_windows_create_condition_variable(void);

void
appl_windows_destroy_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable);

void
appl_windows_wake_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable);

char
appl_windows_sleep_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable,
    struct appl_windows_critical_section * const
        p_critical_section,
    unsigned long int const
        i_timeout_msec);

#include <misc/appl_extern_c_end.h>

/* end-of-file: appl_windows.h */

