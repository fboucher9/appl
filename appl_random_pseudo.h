/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_PSEUDO_H
#error include appl_random_pseudo.h once
#endif /* #if defined INC_APPL_RANDOM_PSEUDO_H */

#define INC_APPL_RANDOM_PSEUDO_H

/* Header file dependency */
#if ! defined INC_APPL_RANDOM_H
#error include appl_random.h before appl_random_pseudo.h
#endif /* #if ! defined INC_APPL_RANDOM_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_random_pseudo;

//
//
//
class appl_random_pseudo : public appl_random
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            unsigned long int const
                i_seed,
            struct appl_random * * const
                r_random);

        appl_random_pseudo();

        virtual
        ~appl_random_pseudo();

        enum appl_status
            f_init(
                unsigned long int const * const
                    p_seed);

    protected:

    private:

        unsigned long int
            m_seed;

        unsigned long int
            ul_padding[1u];

        appl_random_pseudo(
            class appl_random_pseudo const & r);

        class appl_random_pseudo &
            operator =(
                class appl_random_pseudo const & r);

        virtual
        enum appl_status
        v_pick(
            unsigned long int const
                i_value_max,
            unsigned long int * const
                r_value);

}; // class appl_random_pseudo

/* end-of-file: appl_random_pseudo.h */
