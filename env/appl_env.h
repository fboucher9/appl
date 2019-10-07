/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_env_h
{
    inc_appl_env_h =
        /* Header file dependencies */
        inc_appl_object_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_env : public appl_object
{
    public:

        appl_env(
            struct appl_context * const
                p_context);

        virtual
        ~appl_env();

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

        appl_env(
            struct appl_env const & r);

        struct appl_env &
            operator =(
                struct appl_env const & r);

}; // struct appl_env

/* end-of-file: appl_env.h */
