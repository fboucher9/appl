/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_STD_MGR_H
#error include appl_random_std_mgr.h once
#endif /* #if defined INC_APPL_RANDOM_STD_MGR_H */

#define INC_APPL_RANDOM_STD_MGR_H

/* Header file dependency */
#if ! defined INC_APPL_RANDOM_MGR_H
#error include appl_random_mgr.h before appl_random_std_mgr.h
#endif /* #if ! defined INC_APPL_RANDOM_MGR_H */

struct appl_context;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_random_std_mgr;

//
//
//
class appl_random_std_mgr : public appl_random_mgr
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            class appl_random_mgr * * const
                r_random_mgr);

    protected:

        appl_random_std_mgr();

        virtual
        ~appl_random_std_mgr();

    private:

        appl_random_std_mgr(
            class appl_random_std_mgr const & r);

        class appl_random_std_mgr &
            operator =(
                class appl_random_std_mgr const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            init(void);

        virtual
        enum appl_status
        v_generate_seed(
            unsigned long int * const
                r_seed);

        virtual
        enum appl_status
        v_create_node(
            unsigned long int const
                i_seed,
            struct appl_random * * const
                r_node);

}; // class appl_random_std_mgr

/* end-of-file: appl_random_std_mgr.h */
