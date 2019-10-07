/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_h
{
    inc_appl_bits_h = 1
        /* Header file dependencies */
        + inc_appl_object_h
        + inc_appl_predefines_h

}; /* enum guard_appl_bits_h */

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_bits : public appl_object
{
    public:

        appl_bits(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bits();

        virtual
        enum appl_status
            v_read(
                unsigned char const
                    i_count,
                unsigned long int * const
                    r_value);

        virtual
        enum appl_status
            v_write(
                unsigned char const
                    i_count,
                unsigned long int const
                    i_value);

    protected:

    private:

}; // struct appl_bits

/* end-of-file: appl_bits.h */
