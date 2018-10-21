/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_LOG_H
#error include appl_log.h once
#endif /* #if defined INC_APPL_LOG_H */

#define INC_APPL_LOG_H

/* Header file dependency */
#if ! defined INC_APPL_LOG_HANDLE_H
#error include appl_log_handle.h before
#endif /* #if ! defined INC_APPL_LOG_HANDLE_H */

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_log : public appl_heap_object
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
