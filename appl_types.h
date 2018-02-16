/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_TYPES_H)
#error include appl_types.h once
#endif /* #if defined(INC_APPL_TYPES_H) */

#define INC_APPL_TYPES_H

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
#if defined __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wlong-long"
typedef signed long long int appl_sll_t;
typedef unsigned long long int appl_ull_t;
#pragma GCC diagnostic pop
#else /* #if defined __GNUC__ */
typedef signed long long int appl_sll_t;
typedef unsigned long long int appl_ull_t;
#endif /* #if defined __GNUC__ */

/* end-of-file: appl_types.h */
