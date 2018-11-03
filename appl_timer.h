/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_TIMER_H
#error include appl_timer.h once
#endif /* #if defined INC_APPL_TIMER_H */

#define INC_APPL_TIMER_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

struct appl_timer_descriptor;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_timer : public appl_object
{
    public:

        virtual
        enum appl_status
            v_schedule(
                struct appl_timer_descriptor const * const
                    p_timer_descriptor);

    protected:

        appl_timer();

        virtual
        ~appl_timer();

    private:

        appl_timer(
            struct appl_timer const & r);

        struct appl_timer &
            operator =(
                struct appl_timer const & r);

}; // struct appl_timer

/* end-of-file: appl_timer.h */
