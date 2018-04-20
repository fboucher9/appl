/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ENV_STD_H
#error include appl_env_std.h once
#endif /* #if defined INC_APPL_ENV_STD_H */

#define INC_APPL_ENV_STD_H

/* Header file dependency */
#if ! defined INC_APPL_ENV_H
#error include appl_env.h before appl_env_std.h
#endif /* #if ! defined INC_APPL_ENV_H */

/* Assert OS */
#if ! defined APPL_OS_LINUX
#error include only from linux build
#endif /* #if ! defined APPL_OS_LINUX */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_env_std;

//
//
//
class appl_env_std : public appl_env
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_context * const
                p_context,
            class appl_env * * const
                r_env);

    protected:

        appl_env_std();

        virtual
        ~appl_env_std();

        virtual
        enum appl_status
            v_get(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                struct appl_string * * const
                    r_string);

        virtual
        enum appl_status
            v_set(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                unsigned char const * const
                    p_value_min,
                unsigned char const * const
                    p_value_max);

    private:

        appl_env_std(
            class appl_env_std const & r);

        class appl_env_std &
            operator =(
                class appl_env_std const & r);

        static
        void
        s_new(
            void * const
                p_placement);

}; // class appl_env_std

/* end-of-file: appl_env_std.h */
