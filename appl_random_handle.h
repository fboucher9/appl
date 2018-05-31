/* See LICENSE for license details */

/*

Module: appl_random_handle.h

Description:

    Pseudo-random number generator.

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_HANDLE_H
#error include appl_random_handle.h once
#endif /* #if defined INC_APPL_RANDOM_HANDLE_H */

#define INC_APPL_RANDOM_HANDLE_H

/* Header file dependency */
#if ! defined INC_APPL_STATUS_H
#error include appl_status.h before appl_random_handle.h
#endif /* #if ! defined INC_APPL_STATUS_H */

struct appl_object;

struct appl_context;

enum appl_random_type
{
    /* Slower crypto-safe method, seed is ignored */
    appl_random_type_crypto = 1,

    /* Faster method, seed is required */
    appl_random_type_pseudo = 2

}; /* enum appl_random_type */

struct appl_random_descriptor
{
    /* Select a seed for pseudo type */
    unsigned long int
        i_seed;

    /* -- */

    enum appl_random_type
        e_type;

    unsigned int
        ui_padding[1u];

}; /* struct appl_random_descriptor */

struct appl_random;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_random_create(
    struct appl_context * const
        p_context,
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_random);

struct appl_object *
appl_random_parent(
    struct appl_random * const
        p_random);

struct appl_object const *
appl_random_const_parent(
    struct appl_random const * const
        p_random);

enum appl_status
appl_random_pick(
    struct appl_random * const
        p_random,
    unsigned long int const
        i_value_max,
    unsigned long int * const
        r_value);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_random_handle.h */