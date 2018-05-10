/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_STRING_H
#error include appl_string.h once
#endif /* #if defined INC_APPL_STRING_H */

#define INC_APPL_STRING_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_string;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

//
//
//
struct appl_string : public appl_object
{
    public:

        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_cur,
                unsigned char const * const
                    p_buf_max,
                unsigned long int const
                    i_alloc_len,
                struct appl_string * * const
                    r_string);

        virtual
        enum appl_status
            v_read(
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
                    p_buf_max);

    protected:

    private:

        unsigned char *
            m_buf_min;

        unsigned char *
            m_buf_read;

        unsigned char *
            m_buf_write;

        unsigned char *
            m_buf_max;

        void *
            pv_padding[1u];

        appl_string();

        virtual
        ~appl_string();

        appl_string(
            struct appl_string const & r);

        struct appl_string &
            operator =(
                struct appl_string const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        enum appl_status
            init(
                struct appl_string_descriptor const * const
                    p_string_descriptor);

        virtual
        enum appl_status
            v_cleanup(void);

}; // struct appl_string

/* end-of-file: appl_string.h */
