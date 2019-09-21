/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_service_h
{
    inc_appl_bits_service_h = 1
        /* Header file dependencies */
        + inc_appl_status_h
        + inc_appl_predefines_h

}; /* enum guard_appl_bits_service_h */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_bits_service
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                struct appl_bits_descriptor const * const
                    p_descriptor,
                struct appl_bits * * const
                    r_bits);

        static
        enum appl_status
            s_destroy(
                struct appl_bits * const
                    p_bits);

        static
        enum appl_status
            s_read(
                struct appl_bits * const
                    p_bits,
                unsigned char const
                    i_count,
                unsigned long int * const
                    r_value);

        static
        enum appl_status
            s_write(
                struct appl_bits * const
                    p_bits,
                unsigned char const
                    i_count,
                unsigned long int const
                    i_value);

}; // class appl_bits_service

/* end-of-file: appl_bits_service.h */
