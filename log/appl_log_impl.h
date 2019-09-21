/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_log_impl_h
{
    inc_appl_log_impl_h =
        /* Header file dependency */
        inc_appl_log_handle_h
};

struct appl_context;

/* Assert compiler */
#include <appl_assert_cplusplus.h>

//
//
//
class appl_log_impl
{
    public:

        appl_log_impl();

        ~appl_log_impl();

        enum appl_status
            f_print(
                struct appl_context * const
                    p_context,
                enum appl_log_level const
                    e_level,
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

    private:

        unsigned char
            uc_padding[8u];

        appl_log_impl(
            class appl_log_impl const & r);

        class appl_log_impl &
            operator =(
                class appl_log_impl const & r);

}; // class appl_log_impl

/* end-of-file: appl_log_impl.h */
