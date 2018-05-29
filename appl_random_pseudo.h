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
            struct appl_context * const
                p_context,
            unsigned long int const
                i_seed,
            struct appl_random * * const
                r_random);

    protected:

        appl_random_pseudo();

        virtual
        ~appl_random_pseudo();

    private:

        unsigned long int
            m_seed;

        appl_random_pseudo(
            class appl_random_pseudo const & r);

        class appl_random_pseudo &
            operator =(
                class appl_random_pseudo const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            init(
                unsigned long int const * const
                    p_seed);

        virtual
        enum appl_status
        v_pick(
            unsigned long int const
                i_value_max,
            unsigned long int * const
                r_value);

}; // class appl_random_pseudo

/* end-of-file: appl_random_pseudo.h */
