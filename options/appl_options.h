/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_options_h
{
    inc_appl_options_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

struct appl_options;

//
//
//
struct appl_options : public appl_object
{
    public:

        virtual
        enum appl_status
            v_count(
                unsigned long int * const
                    r_count) const;

        virtual
        enum appl_status
            v_get(
                unsigned long int const
                    i_index,
                unsigned char const * * const
                    r_buf_min,
                unsigned char const * * const
                    r_buf_max) const;

        virtual
        enum appl_status
            v_write(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                unsigned long int * const
                    p_count,
                char * const
                    p_ready);

        virtual
        enum appl_status
            v_append_argument(
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max);

    protected:

        appl_options();

        virtual
        ~appl_options();

    private:

        appl_options(
            struct appl_options const & r);

        struct appl_options &
            operator =(
                struct appl_options const & r);

}; // struct appl_options

/* end-of-file: appl_options.h */
