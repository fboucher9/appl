/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_w32_crypto_h
{
    inc_appl_random_w32_crypto_h =
        /* Header file dependencies */
        inc_appl_random_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_random_w32_crypto;

//
//
//
class appl_random_w32_crypto : public appl_random
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_random * * const
                r_random);

        appl_random_w32_crypto();

        virtual
        ~appl_random_w32_crypto();

    protected:

    private:

        appl_random_w32_crypto(
            class appl_random_w32_crypto const & r);

        class appl_random_w32_crypto &
            operator =(
                class appl_random_w32_crypto const & r);

        virtual
        appl_size_t
        v_cleanup(void);

        virtual
        enum appl_status
        v_pick(
            unsigned long int const
                i_value_max,
            unsigned long int * const
                r_value);

}; // class appl_random_w32_crypto

/* end-of-file: appl_random_w32_crypto.h */
