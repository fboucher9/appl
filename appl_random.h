/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_RANDOM_H
#error include appl_random.h once
#endif /* #if defined INC_APPL_RANDOM_H */

#define INC_APPL_RANDOM_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_random.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

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

        virtual
        enum appl_status
            v_pick(
                unsigned long int const
                    i_value_max,
                unsigned long int * const
                    r_value);

    protected:

        appl_random();

        virtual
        ~appl_random();

    private:

        appl_random(
            struct appl_random const & r);

        struct appl_random &
            operator =(
                struct appl_random const & r);

}; // struct appl_random

/* end-of-file: appl_random.h */
