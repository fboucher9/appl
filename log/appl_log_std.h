/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_log_std_h
{
    inc_appl_log_std_h =
        /* Header file dependency */
        inc_appl_log_h
        + inc_appl_log_impl_h
};

struct appl_object;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
class appl_log_std : public appl_log
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_allocator * const
                    p_allocator,
                class appl_log_std * * const
                    r_instance);

        appl_log_std();

        virtual
        ~appl_log_std();

    protected:

    private:

        class appl_log_impl
            m_log_impl;

        appl_log_std(
            class appl_log_std const & r);

        class appl_log_std &
            operator =(
                class appl_log_std const & r);

        virtual
        enum appl_status
            v_print(
                enum appl_log_level const
                    e_level,
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

}; // class appl_log_std

/* end-of-file: appl_log_std.h */
