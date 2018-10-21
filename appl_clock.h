/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_CLOCK_H
#error include appl_clock.h once
#endif /* #if defined INC_APPL_CLOCK_H */

#define INC_APPL_CLOCK_H

/* Header file dependency */
#if ! defined INC_APPL_HEAP_OBJECT_H
#error include appl_heap_object.h before
#endif /* #if ! defined INC_APPL_HEAP_OBJECT_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_clock;

//
//
//
class appl_clock : public appl_heap_object
{
    public:

        virtual
        enum appl_status
        v_read(
            unsigned long int const
                i_time_freq,
            unsigned long int * const
                p_time_count);

        virtual
        enum appl_status
        v_delay(
            unsigned long int const
                i_time_freq,
            unsigned long int const
                i_time_count);

    protected:

        appl_clock();

        virtual
        ~appl_clock();

    private:

        appl_clock(
            class appl_clock const & r);

        class appl_clock &
            operator =(
                class appl_clock const & r);

}; // class appl_clock

/* end-of-file: appl_clock.h */
