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
struct appl_buf;

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
                struct appl_buf const * const
                    p_ref_buf,
                unsigned long int const
                    i_alloc_len,
                class appl_string * * const
                    r_string);

        virtual
        enum appl_status
            v_length(
                unsigned long int * const
                    r_buf_len) const;

        virtual
        enum appl_status
            v_read(
                struct appl_buf * const
                    p_buf) const;

        virtual
        enum appl_status
            v_write(
                struct appl_buf * const
                    p_buf);

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
            m_buf;

        unsigned long int
            m_data_len;

        unsigned long int
            m_alloc_len;

        unsigned long int
            ul_padding[1u];

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
