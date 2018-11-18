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

struct appl_string;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

class appl_env;

//
//
//
class appl_env : public appl_object
{
    public:

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

    protected:

        appl_env();

        virtual
        ~appl_env();

    private:

        appl_env(
            class appl_env const & r);

        class appl_env &
            operator =(
                class appl_env const & r);

}; // class appl_env

/* end-of-file: appl_env.h */
