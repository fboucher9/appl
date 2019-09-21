/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_base_h
{
    inc_appl_bits_base_h = 1
        /* Header file dependencies */
        + inc_appl_bits_h

}; /* enum guard_appl_bits_h */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_bits_base : public appl_bits
{
    public:

        appl_bits_base(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bits_base();

        virtual
        enum appl_status
            v_consume(
                unsigned char * const
                    r_value);

        virtual
        enum appl_status
            v_produce(
                unsigned char const
                    i_value);

    protected:

        /* -- */

        appl_ull_t
            i_accum;

        /* -- */

        unsigned char
            m_count;

        unsigned char
            uc_padding[7u];

        /* -- */

    private:

        appl_bits_base(
            class appl_bits_base const & r);

        class appl_bits_base &
            operator =(
                class appl_bits_base const & r);

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

}; // class appl_bits_base

/* end-of-file: appl_bits_base.h */
