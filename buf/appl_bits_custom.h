/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_custom_h
{
    inc_appl_bits_custom_h = 1
        /* Header file dependencies */
        + inc_appl_bits_base_h
        + inc_appl_bits_descriptor_h
}; /* enum guard_appl_bits_custom_h */

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_bits_custom : public appl_bits_base
{
    public:

        appl_bits_custom(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bits_custom();

        enum appl_status
            f_init(
                struct appl_bits_custom_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        /* -- */

        struct appl_bits_custom_descriptor
            m_descriptor;

        /* -- */

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

}; // class appl_bits_custom

/* end-of-file: appl_bits_custom.h */
