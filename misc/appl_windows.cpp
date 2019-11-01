/* See LICENSE for license details */

/*

*/

#include <appl_types.h>

#include <misc/appl_windows.h>

#include <misc/appl_unused.h>

#if defined APPL_OS_WINDOWS

#define WINVER 0x601

#define _WIN32_WINNT 0x601

#include <windows.h>

#endif /* #if defined APPL_OS_WINDOWS */

//
//
//
char
appl_windows_time_begin_period(
    unsigned long int const
        i_period_msec)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    MMRESULT
        e_time_result;

    e_time_result =
        timeBeginPeriod(
            i_period_msec);

    b_result =
        (
            TIMERR_NOERROR
            == e_time_result);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_period_msec);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_time_begin_period()

//
//
//
char
appl_windows_time_end_period(
    unsigned long int const
        i_period_msec)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    MMRESULT
        e_time_result;

    e_time_result =
        timeEndPeriod(
            i_period_msec);

    b_result =
        (
            TIMERR_NOERROR
            == e_time_result);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_period_msec);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_time_end_period()

//
//
//
char
appl_windows_query_performance_frequency(
    appl_ull_t * const
        r_value)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    BOOL
        b_query_result;

    LARGE_INTEGER
        o_query_value;

    b_query_result =
        QueryPerformanceFrequency(
            &(
                o_query_value));

    if (
        b_query_result)
    {
        *(
            r_value) =
            o_query_value.QuadPart;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        r_value);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_query_performance_frequency()

//
//
//
char
appl_windows_query_performance_counter(
    appl_ull_t * const
        r_value)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    LARGE_INTEGER
        o_query_value;

    BOOL const
        b_query_result =
        QueryPerformanceCounter(
            &(
                o_query_value));

    if (
        b_query_result)
    {
        *(
            r_value) =
            o_query_value.QuadPart;

        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        r_value);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_query_performance_counter()

//
//
//
char
appl_windows_sleep_ex(
    unsigned long int const
        i_count_msec,
    char const
        b_alertable)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    if (
        0
        == SleepEx(
            i_count_msec,
            b_alertable))
    {
        b_result =
            1;
    }
    else
    {
        b_result =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        i_count_msec,
        b_alertable);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_sleep_ex()

//
//
//
unsigned long int
appl_windows_get_environment_variable(
    char const * const
        lpName,
    char * const
        lpBuffer,
    unsigned long int const
        nSize)
{
    unsigned long int
        i_result;

#if defined APPL_OS_WINDOWS

    i_result =
        GetEnvironmentVariableA(
            lpName,
            lpBuffer,
            nSize);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        lpName,
        lpBuffer,
        nSize);

    i_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        i_result;

} // appl_windows_get_environment_variable()

//
//
//
char
appl_windows_set_environment_variable(
    char const * const
        lpName,
    char const * const
        lpValue)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    b_result =
        (
            0
            != SetEnvironmentVariableA(
                lpName,
                lpValue));

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        lpName,
        lpValue);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_set_environment_variable()

#if defined APPL_OS_WINDOWS
union appl_windows_critical_section_ptr
{
    struct appl_windows_critical_section *
        p_opaque;

    CRITICAL_SECTION *
        p_structure;

    HLOCAL
        p_void;

};
#endif /* #if defined APPL_OS_WINDOWS */

//
//
//
struct appl_windows_critical_section *
appl_windows_create_critical_section(void)
{
    struct appl_windows_critical_section *
        p_critical_section;

#if defined APPL_OS_WINDOWS

    union appl_windows_critical_section_ptr
        o_critical_section_ptr;

    UINT const
        i_placement_length =
        sizeof(
            CRITICAL_SECTION);

    o_critical_section_ptr.p_void =
        LocalAlloc(
            LMEM_FIXED,
            i_placement_length);

    if (
        o_critical_section_ptr.p_void)
    {
        InitializeCriticalSection(
            o_critical_section_ptr.p_structure);

        p_critical_section =
            o_critical_section_ptr.p_opaque;
    }
    else
    {
        p_critical_section =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    p_critical_section =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        p_critical_section;

} // appl_windows_create_critical_section()

//
//
//
void
appl_windows_destroy_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section)
{

#if defined APPL_OS_WINDOWS

    union appl_windows_critical_section_ptr
        o_critical_section_ptr;

    o_critical_section_ptr.p_opaque =
        p_critical_section;

    DeleteCriticalSection(
        o_critical_section_ptr.p_structure);

    LocalFree(
        o_critical_section_ptr.p_void);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_critical_section);

#endif /* #if defined APPL_OS_WINDOWS */

} // appl_windows_destroy_critical_section()

//
//
//
void
appl_windows_enter_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section)
{

#if defined APPL_OS_WINDOWS

    union appl_windows_critical_section_ptr
        o_critical_section_ptr;

    o_critical_section_ptr.p_opaque =
        p_critical_section;

    EnterCriticalSection(
        o_critical_section_ptr.p_structure);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_critical_section);

#endif /* #if defined APPL_OS_WINDOWS */

}

void
appl_windows_leave_critical_section(
    struct appl_windows_critical_section * const
        p_critical_section)
{

#if defined APPL_OS_WINDOWS

    union appl_windows_critical_section_ptr
        o_critical_section_ptr;

    o_critical_section_ptr.p_opaque =
        p_critical_section;

    LeaveCriticalSection(
        o_critical_section_ptr.p_structure);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_critical_section);

#endif /* #if defined APPL_OS_WINDOWS */

}

#if defined APPL_OS_WINDOWS
union appl_windows_condition_variable_ptr
{
    struct appl_windows_condition_variable *
        p_opaque;

    CONDITION_VARIABLE *
        p_structure;

    HLOCAL
        p_void;

};
#endif /* #if defined APPL_OS_WINDOWS */

//
//
//
struct appl_windows_condition_variable *
appl_windows_create_condition_variable(void)
{
    struct appl_windows_condition_variable *
        p_this;

#if defined APPL_OS_WINDOWS

    union appl_windows_condition_variable_ptr
        o_condition_variable_ptr;

    UINT const
        i_placement_length =
        sizeof(
            CONDITION_VARIABLE);

    o_condition_variable_ptr.p_void =
        LocalAlloc(
            LMEM_FIXED,
            i_placement_length);

    if (
        o_condition_variable_ptr.p_void)
    {
        InitializeConditionVariable(
            o_condition_variable_ptr.p_structure);

        p_this =
            o_condition_variable_ptr.p_opaque;
    }
    else
    {
        p_this =
            0;
    }

#else /* #if defined APPL_OS_WINDOWS */

    p_this =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        p_this;

} // appl_windows_create_condition_variable()

//
//
//
void
appl_windows_destroy_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable)
{
#if defined APPL_OS_WINDOWS

    union appl_windows_condition_variable_ptr
        o_condition_variable_ptr;

    o_condition_variable_ptr.p_opaque =
        p_condition_variable;

    LocalFree(
        o_condition_variable_ptr.p_void);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_condition_variable);

#endif /* #if defined APPL_OS_WINDOWS */

} // appl_windows_condition_variable()

//
//
//
void
appl_windows_wake_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable)
{
#if defined APPL_OS_WINDOWS

    union appl_windows_condition_variable_ptr
        o_condition_variable_ptr;

    o_condition_variable_ptr.p_opaque =
        p_condition_variable;

    WakeConditionVariable(
        o_condition_variable_ptr.p_structure);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_condition_variable);

#endif /* #if defined APPL_OS_WINDOWS */

} // appl_windows_wake_condition_variable()

//
//
//
char
appl_windows_sleep_condition_variable(
    struct appl_windows_condition_variable * const
        p_condition_variable,
    struct appl_windows_critical_section * const
        p_critical_section,
    unsigned long int const
        i_timeout_msec)
{
    char
        b_result;

#if defined APPL_OS_WINDOWS

    union appl_windows_condition_variable_ptr
        o_condition_variable_ptr;

    o_condition_variable_ptr.p_opaque =
        p_condition_variable;

    union appl_windows_critical_section_ptr
        o_critical_section_ptr;

    o_critical_section_ptr.p_opaque =
        p_critical_section;

    b_result =
        0
        != SleepConditionVariableCS(
            o_condition_variable_ptr.p_structure,
            o_critical_section_ptr.p_structure,
            i_timeout_msec);

#else /* #if defined APPL_OS_WINDOWS */

    appl_unused(
        p_condition_variable,
        p_critical_section,
        i_timeout_msec);

    b_result =
        0;

#endif /* #if defined APPL_OS_WINDOWS */

    return
        b_result;

} // appl_windows_sleep_condition_variable()

/* end-of-file: appl_windows.h */
