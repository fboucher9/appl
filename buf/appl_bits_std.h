/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_bits_std_h
{
    inc_appl_bits_std_h = 1
        /* Header file dependencies */
        + inc_appl_bits_base_h
        + inc_appl_bits_handle_h
}; /* enum guard_appl_bits_std_h */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_bits_std : public appl_bits_base
{
    public:

        appl_bits_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_bits_std();

        enum appl_status
            f_init(
                struct appl_bits_descriptor const * const
                    p_descriptor);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        /* -- */

        struct appl_bits_descriptor
            m_descriptor;

        /* -- */

        char
            b_descriptor;

        unsigned char
            uc_padding[7u];

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

}; // class appl_bits_std

/* end-of-file: appl_bits_std.h */
