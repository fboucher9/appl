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

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
class appl_context;

// Predefine
class appl_string;

//
//
//
class appl_string : public appl_object
{
    public:

        static
        enum appl_status
            s_create(
                class appl_context * const
                    p_context,
                unsigned long int const
                    i_alloc_len,
                class appl_string * * const
                    r_string);

        static
        enum appl_status
            s_create_ref(
                class appl_context * const
                    p_context,
                unsigned char const * const
                    p_buf_min,
                unsigned char const * const
                    p_buf_max,
                class appl_string * * const
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

        static
        class appl_string const *
            convert_const_handle(
                struct appl_string_handle const * const
                    p_string_handle);

        static
        class appl_string *
            convert_handle(
                struct appl_string_handle * const
                    p_string_handle);

        struct appl_string_handle *
            get_handle(void);

        struct appl_string_handle const *
            get_const_handle(void) const;

    protected:

        unsigned char *
            m_buf_min;

        unsigned char *
            m_buf_cur;

        unsigned char *
            m_buf_max;

        void *
            pv_padding[1u];

        appl_string();

        virtual
        ~appl_string();

    private:

        appl_string(
            class appl_string const & r);

        class appl_string &
            operator =(
                class appl_string const & r);

        static
        void
            s_new(
                void * const
                    p_placement);

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

}; // class appl_string

/* end-of-file: appl_string.h */
