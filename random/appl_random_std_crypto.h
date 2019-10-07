/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_std_crypto_h
{
    inc_appl_random_std_crypto_h =
        /* Header file dependencies */
        inc_appl_random_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

class appl_random_std_crypto;

//
//
//
class appl_random_std_crypto : public appl_random
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_random * * const
                r_random);

#if 0
        static
        enum appl_status
        s_destroy(
            struct appl_allocator * const
                p_allocator,
            struct appl_random * const
                p_random);
#endif

        appl_random_std_crypto(
            struct appl_context * const
                p_context);

        virtual
        ~appl_random_std_crypto();

    protected:

    private:

        appl_random_std_crypto(
            class appl_random_std_crypto const & r);

        class appl_random_std_crypto &
            operator =(
                class appl_random_std_crypto const & r);

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

}; // class appl_random_std_crypto

/* end-of-file: appl_random_std_crypto.h */
