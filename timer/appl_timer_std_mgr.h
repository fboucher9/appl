/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_timer_std_mgr_h
{
    inc_appl_timer_std_mgr_h =
        /* Header file dependency */
        inc_appl_timer_mgr_h
};

/* Predefine */
struct appl_allocator;

/* Predefine */
struct appl_timer;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_timer_std_mgr : public appl_timer_mgr
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_timer_mgr * * const
                    r_timer_mgr);

        appl_timer_std_mgr();

        virtual
        ~appl_timer_std_mgr();

        enum appl_status
            f_init(void);

    protected:

    private:

        appl_timer_std_mgr(
            class appl_timer_std_mgr const & r);

        class appl_timer_std_mgr &
            operator =(
                class appl_timer_std_mgr const & r);

        virtual
        enum appl_status
            v_create(
                struct appl_timer * * const
                    r_timer);

}; // class appl_timer_std_mgr

/* end-of-file: appl_timer_std_mgr.h */
