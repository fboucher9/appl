/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_STD_CRYPTO_H
#error include appl_random_std_crypto.h once
#endif /* #if defined INC_APPL_RANDOM_STD_CRYPTO_H */

#define INC_APPL_RANDOM_STD_CRYPTO_H

/* Header file dependency */
#if ! defined INC_APPL_RANDOM_H
#error include appl_random.h before appl_random_std_crypto.h
#endif /* #if ! defined INC_APPL_RANDOM_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_random_std_crypto;

//
//
//
class appl_random_std_crypto : public appl_random
{
    friend struct appl_heap;

    public:

        static
        enum appl_status
        s_create(
            struct appl_heap * const
                p_heap,
            struct appl_random * * const
                r_random);

    protected:

        appl_random_std_crypto();

        virtual
        ~appl_random_std_crypto();

    private:

        appl_random_std_crypto(
            class appl_random_std_crypto const & r);

        class appl_random_std_crypto &
            operator =(
                class appl_random_std_crypto const & r);

        virtual
        enum appl_status
        v_pick(
            unsigned long int const
                i_value_max,
            unsigned long int * const
                r_value);

}; // class appl_random_std_crypto

/* end-of-file: appl_random_std_crypto.h */
