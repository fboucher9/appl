/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_random_h
{
    inc_appl_random_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if defined __cplusplus */

//
//
//
struct appl_random : public appl_object
{
    public:

        appl_random(
            struct appl_context * const
                p_context);

        virtual
        ~appl_random();

        virtual
        enum appl_status
            v_pick(
                unsigned long int const
                    i_value_max,
                unsigned long int * const
                    r_value);

    protected:

    private:

        appl_random(
            struct appl_random const & r);

        struct appl_random &
            operator =(
                struct appl_random const & r);

}; // struct appl_random

/* end-of-file: appl_random.h */
