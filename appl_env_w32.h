/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_ENV_W32_H
#error include appl_env_w32.h once
#endif /* #if defined INC_APPL_ENV_W32_H */

#define INC_APPL_ENV_W32_H

/* Header file dependency */
#if ! defined INC_APPL_ENV_H
#error include appl_env.h before appl_env_w32.h
#endif /* #if ! defined INC_APPL_ENV_H */

/* Assert OS */
#if ! defined APPL_OS_WINDOWS
#error include only from windows build
#endif /* #if ! defined APPL_OS_WINDOWS */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_env_w32;

//
//
//
class appl_env_w32 : public appl_env
{
    // friend struct appl_heap;

    public:

        static
        enum appl_status
        s_create(
            struct appl_heap * const
                p_heap,
            class appl_env * * const
                r_env);

        appl_env_w32();

        virtual
        ~appl_env_w32();

    protected:

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

        appl_env_w32(
            class appl_env_w32 const & r);

        class appl_env_w32 &
            operator =(
                class appl_env_w32 const & r);

}; // class appl_env_w32

/* end-of-file: appl_env_w32.h */
