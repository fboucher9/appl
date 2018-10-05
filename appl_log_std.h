/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LOG_STD_H
#error include appl_log_std.h once
#endif /* #if defined INC_APPL_LOG_STD_H */

#define INC_APPL_LOG_STD_H

/* Header file dependency */
#if ! defined INC_APPL_LOG_H
#error include appl_log.h before
#endif /* #if ! defined INC_APPL_LOG_H */

struct appl_context;

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
                struct appl_context * const
                    p_context,
                class appl_log_std * * const
                    r_instance);

    protected:

        appl_log_std();

        virtual
        ~appl_log_std();

    private:

        static
        void
            s_new(
                void * const
                    p_placement);

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
