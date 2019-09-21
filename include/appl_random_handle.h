/* See LICENSE for license details */

/*

Module: appl_random_handle.h

Description:

    Pseudo-random number generator.

*/

/* Reverse include guard */
enum guard_appl_random_handle_h
{
    inc_appl_random_handle_h =
        /* Header file dependency */
        inc_appl_status_h
};

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

    signed long int
        e_type;

}; /* struct appl_random_descriptor */

struct appl_random;

#include <appl_extern_c_begin.h>

enum appl_status
appl_random_create(
    struct appl_context * const
        p_context,
    struct appl_random_descriptor const * const
        p_descriptor,
    struct appl_random * * const
        r_random);

enum appl_status
appl_random_destroy(
    struct appl_random * const
        p_random);

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

#include <appl_extern_c_end.h>

/* end-of-file: appl_random_handle.h */
