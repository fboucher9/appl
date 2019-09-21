/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_packet_service_h
{
    inc_appl_packet_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
};

/* Assert compiler */
#include <appl_assert_cplusplus.h>

class appl_packet_service
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            struct appl_packet * * const
                r_packet);

        static
        enum appl_status
        s_destroy(
            struct appl_packet * const
                p_packet);

        static
        struct appl_object *
        s_parent(
            struct appl_packet * const
                p_packet);

        static
        struct appl_object const *
        s_const_parent(
            struct appl_packet const * const
                p_packet);

        static
        enum appl_status
        s_set_module(
            struct appl_packet * const
                p_packet,
            struct appl_module * const
                p_module);

        static
        enum appl_status
        s_set_buffer(
            struct appl_packet * const
                p_packet,
            unsigned char * const
                p_buf_min,
            unsigned char * const
                p_buf_max);

        static
        enum appl_status
        s_set_type(
            struct appl_packet * const
                p_packet,
            unsigned long int const
                e_type);

}; // class appl_packet_service

/* end-of-file: appl_packet_service.h */
