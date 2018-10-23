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
struct appl_object;

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
    // friend struct appl_heap;

    public:

        static
        enum appl_status
            s_create(
                struct appl_heap * const
                    p_heap,
                unsigned long int const
                    i_alloc_len,
                struct appl_string * * const
                    r_string);

        virtual
        enum appl_status
            v_length(
                unsigned long int * const
                    r_length) const;

        virtual
        enum appl_status
            v_get(
                unsigned char * * const
                    r_buf_min,
                unsigned char * * const
                    r_buf_max) const;

        appl_string();

        virtual
        ~appl_string();

        enum appl_status
            f_init(
                struct appl_string_descriptor const * const
                    p_string_descriptor);

    protected:

    private:

        unsigned char *
            m_buf_min;

        unsigned char *
            m_buf_max;

        appl_string(
            struct appl_string const & r);

        struct appl_string &
            operator =(
                struct appl_string const & r);

        virtual
        enum appl_status
            v_cleanup(void);

}; // struct appl_string

/* end-of-file: appl_string.h */
