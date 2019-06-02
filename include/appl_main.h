/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_main_h
{
    inc_appl_main_h =
        /* Header file dependency */
        inc_appl_status_h
};

struct appl_context;

struct appl_options;

typedef
enum appl_status
(appl_main_callback)(
    struct appl_context * const
        p_context,
    struct appl_options const * const
        p_options,
    unsigned long int const
        i_shift);

/*

*/
struct appl_main_descriptor
{
    char const * const *
        p_arg_vector_min;

    char const * const *
        p_arg_vector_max;

    /* -- */

    appl_main_callback *
        p_main_callback;

    void *
        pv_padding[1u];

}; /* struct appl_main_descriptor */

#if defined(__cplusplus)
extern "C" {
#endif /* #if defined(__cplusplus) */

void
    appl_main_descriptor_init(
        struct appl_main_descriptor * const
            p_main_descriptor);

void
    appl_main_descriptor_cleanup(
        struct appl_main_descriptor * const
            p_main_descriptor);

void
    appl_main_descriptor_set_arg_vector(
        struct appl_main_descriptor * const
            p_main_descriptor,
        char const * const * const
            p_arg_vector_min,
        char const * const * const
            p_arg_vector_max);

void
    appl_main_descriptor_set_callback(
        struct appl_main_descriptor * const
            p_main_descriptor,
        appl_main_callback * const
            p_main_callback);

int
    appl_main(
        struct appl_main_descriptor const * const
            p_main_descriptor);

#if defined(__cplusplus)
} /* extern "C" */
#endif /* #if defined(__cplusplus) */

/* end-of-file: appl_main.h */
