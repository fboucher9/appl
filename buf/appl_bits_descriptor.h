/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_descriptor_h
{
    inc_appl_bits_descriptor_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_buf_h
        /* ... */
}; /* enum guard_appl_bits_descriptor_h */

typedef
enum appl_status
(appl_bits_consume)(
    void * const
        p_callback_context,
    unsigned char * const
        r_value);

typedef
enum appl_status
(appl_bits_produce)(
    void * const
        p_callback_context,
    unsigned char const
        i_value);

enum appl_bits_type
{
    appl_bits_type_custom = 1,

    appl_bits_type_mem = 2

}; /* enum appl_bits_type */

struct appl_bits_custom_descriptor
{
    appl_bits_consume *
        p_callback_consume;

    appl_bits_produce *
        p_callback_produce;

    /* -- */

    void *
        p_callback_context;

    void *
        pv_padding[1u];

}; /* struct appl_bits_custom_descriptor */

struct appl_bits_mem_descriptor
{
    struct appl_buf
        o_buf;

}; /* struct appl_bits_mem_descriptor */

/*

*/
struct appl_bits_descriptor
{
    enum appl_bits_type
        e_type;

    unsigned int
        ui_padding[3u];

    /* -- */

    union appl_bits_descriptor_data
    {
        struct appl_bits_custom_descriptor
            o_custom_descriptor;

        struct appl_bits_mem_descriptor
            o_mem_descriptor;

    } u;

}; /* struct appl_bits_descriptor */

/* end-of-file: appl_bits_descriptor.h */
