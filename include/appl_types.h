/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_TYPES_H

/* Reverse include guard */
enum guard_appl_types_h
{
    inc_appl_types_h =
        1
};

/*

Macro: APPL_SIZEOF_INT

Description:

    Size in bytes of base type int.

Comments:

    If the automatic detection fails, you may configure the macro value
    from makefile.

*/
#if ! defined APPL_SIZEOF_INT
#if defined __SIZEOF_INT__
/* For gcc and clang, use builtin macro */
#define APPL_SIZEOF_INT __SIZEOF_INT__
#else /* #if defined __SIZEOF_INT__ */
/* Default to 64-bit windows */
#define APPL_SIZEOF_INT 4
#endif /* #if defined __SIZEOF_INT__ */
#endif /* #if ! defined APPL_SIZEOF_INT */

/* Compile-time verification of macro value */
typedef char check_appl_sizeof_int_macro [
    APPL_SIZEOF_INT == sizeof(int) ? 1 : -1 ];

/*

Macro: APPL_SIZEOF_LONG

Description:

    Size in bytes of base type long.


Comments:

    If the automatic detection fails, you may configure the macro value
    from makefile.

*/
#if ! defined APPL_SIZEOF_LONG
#if defined __SIZEOF_LONG__
/* For gcc and clang, use builtin macro */
#define APPL_SIZEOF_LONG __SIZEOF_LONG__
#else /* #if defined __SIZEOF_LONG__ */
/* Default to 64-bit windows */
#define APPL_SIZEOF_LONG 4
#endif /* #if defined __SIZEOF_LONG__ */
#endif /* #if ! defined APPL_SIZEOF_LONG */

/* Compile-time verification of macro value */
typedef char check_appl_sizeof_long_macro [
    APPL_SIZEOF_LONG == sizeof(long) ? 1 : -1 ];

/*

Macro: APPL_SIZEOF_PTR

Description:

    Size in bytes of base type pointer.


Comments:

    If the automatic detection fails, you may configure the macro value
    from makefile.

*/
#if ! defined APPL_SIZEOF_PTR
#if defined __SIZEOF_POINTER__
/* For gcc and clang, use builtin macro */
#define APPL_SIZEOF_PTR __SIZEOF_POINTER__
#else /* #if defined __SIZEOF_POINTER__ */
/* Default to 64-bit windows */
#define APPL_SIZEOF_PTR 8
#endif /* #if defined __SIZEOF_POINTER__ */
#endif /* #if ! defined APPL_SIZEOF_PTR */

/* Compile-time verification of macro value */
typedef char check_appl_sizeof_ptr_macro [
    APPL_SIZEOF_PTR == sizeof(void*) ? 1 : -1 ];

#if defined __GNUC__
#pragma GCC diagnostic ignored "-Wlong-long"
#endif /* #if defined __GNUC__ */

/*

Type: appl_size_t

Description:

    Define an unsigned integer, same size as a pointer.

*/
#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ appl_size_t;
#elif defined(__SIZEOF_SIZE_T__)
#if (8 == __SIZEOF_SIZE_T__)
typedef unsigned long int appl_size_t;
#else /* #if (8 == __SIZEOF_SIZE_T__) */
typedef unsigned int appl_size_t;
#endif /* #if (0 == __SIZEOF_SIZE_T__) */
#elif defined(__amd64) \
    || defined(__amd64__) \
    || defined(__x86_64__) \
    || defined(__x86_64)
typedef unsigned long int appl_size_t;
#elif defined(__i386) \
    || defined(__i386__) \
    || defined(i386) \
    || defined(__i586) \
    || defined(__i586__)
typedef unsigned int appl_size_t;
#else /* #if defined(__SIZE_TYPE__) */
/* Note: include stddef.h from appl_os.h */
typedef size_t appl_size_t;
#endif /* #if defined(__SIZE_TYPE__) */

/*

Type: appl_ptrdiff_t

Description:

    Define a signed integer, same size as a pointer.

*/
#if defined(__PTRDIFF_TYPE__)
typedef __PTRDIFF_TYPE__ appl_ptrdiff_t;
#elif defined(__SIZEOF_PTRDIFF_T__)
#if (8 == __SIZEOF_PTRDIFF_T__)
typedef signed long int appl_ptrdiff_t;
#else /* #if (8 == __SIZEOF_PTRDIFF_T__) */
typedef signed int appl_ptrdiff_t;
#endif /* #if (8 == __SIZEOF_PTRDIFF_T__) */
#elif defined(__amd64) \
    || defined(__amd64__) \
    || defined(__x86_64__) \
    || defined(__x86_64)
typedef signed long int appl_ptrdiff_t;
#elif defined(__i386) \
    || defined(__i386__) \
    || defined(i386) \
    || defined(__i586) \
    || defined(__i586__)
typedef signed int appl_ptrdiff_t;
#else /* #if defined(__PTRDIFF_TYPE__) */
typedef ptrdiff_t appl_ptrdiff_t;
#endif /* #if defined(__PTRDIFF_TYPE__) */

/*

Type: appl_ull_t, appl_sll_t

Description:

    Define signed and unsigned long long integers.

Comments:

    -   This is required for GCC to avoid warnings when using long long type.

    -   For Visual C++ compiler, the long long type is not available for older
        versions of the compiler.  Use __int64 in that case.

*/
typedef signed long long int appl_sll_t;
typedef unsigned long long int appl_ull_t;

#if defined __GNUC__
#pragma GCC diagnostic warning "-Wlong-long"
#endif /* #if defined __GNUC__ */

/* end-of-file: appl_types.h */
