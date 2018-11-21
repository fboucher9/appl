/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_log_h
{
    inc_appl_log_h =
        /* Header file dependency */
        inc_appl_log_handle_h
        + inc_appl_object_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_log : public appl_object
{
    public:

        virtual
        enum appl_status
            v_print(
                enum appl_log_level const
                    e_level,
                unsigned char const * const
                    p_message_min,
                unsigned char const * const
                    p_message_max);

    protected:

        appl_log();

        virtual
        ~appl_log();

    private:

        appl_log(
            struct appl_log const & r);

        struct appl_log &
            operator =(
                struct appl_log const & r);

}; // struct appl_log

/* end-of-file: appl_log.h */