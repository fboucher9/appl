/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_std_h
{
    inc_appl_env_std_h =
        /* Header file dependencies */
        inc_appl_env_h
};

/* Assert OS */
#include <misc/appl_assert_linux.h>

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

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
            struct appl_allocator * const
                p_allocator,
            struct appl_env * * const
                r_env);

        static
        enum appl_status
        s_destroy(
            struct appl_allocator * const
                p_allocator,
            struct appl_env * const
                p_env);

        appl_env_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_env_std();

        enum appl_status
            f_init(void);

    protected:

        virtual
        enum appl_status
            v_get(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                struct appl_string * * const
                    r_string) const;

        virtual
        enum appl_status
            v_query(
                unsigned char const * const
                    p_name_min,
                unsigned char const * const
                    p_name_max,
                void (* p_query_callback)(
                    void * const
                        p_query_context,
                    unsigned char const * const
                        p_value_min,
                    unsigned char const * const
                        p_value_max),
                void * const
                    p_query_context) const;

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

        virtual
        appl_size_t
            v_cleanup(void);

}; // class appl_env_std

/* end-of-file: appl_env_std.h */
