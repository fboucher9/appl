/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_packet_handle_h
{
    inc_appl_packet_handle_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

#define APPL_PACKET_TYPE_NONE (0ul)

#define APPL_PACKET_TYPE_BINARY (1ul)

#define APPL_PACKET_TYPE_TEXT (2ul)

#define APPL_PACKET_TYPE_FLUSH (3ul)

/* Predefine */
struct appl_object;

/* Predefine */
struct appl_packet;

/* Predefine */
struct appl_module;

#if defined __cplusplus
extern "C" {
#endif /* #if defined __cplusplus */

enum appl_status
appl_packet_create(
    struct appl_context * const
        p_context,
    struct appl_packet * * const
        r_packet);

enum appl_status
appl_packet_destroy(
    struct appl_packet * const
        p_packet);

struct appl_object *
appl_packet_parent(
    struct appl_packet * const
        p_packet);

struct appl_object const *
appl_packet_const_parent(
    struct appl_packet const * const
        p_packet);

enum appl_status
appl_packet_set_module(
    struct appl_packet * const
        p_packet,
    struct appl_module * const
        p_module);

enum appl_status
appl_packet_set_buffer(
    struct appl_packet * const
        p_packet,
    unsigned char * const
        p_buf_min,
    unsigned char * const
        p_buf_max);

enum appl_status
appl_packet_set_type(
    struct appl_packet * const
        p_packet,
    unsigned long int const
        e_type);

#if defined __cplusplus
} /* extern "C" */
#endif /* #if defined __cplusplus */

/* end-of-file: appl_packet_handle.h */
