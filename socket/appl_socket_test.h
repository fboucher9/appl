/* See LICENSE for license details */

/*

*/

struct appl_context;

struct appl_options;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

void
    appl_socket_test_1(
        struct appl_context * const
            p_context);

/* socket tool:
    udp addr port addr port
    client addr port addr port
    server addr port */
void
    appl_socket_test_2_manual(
        struct appl_context * const
            p_context,
        struct appl_options const * const
            p_options,
        unsigned int const
            i_shift);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_socket_test.h */
