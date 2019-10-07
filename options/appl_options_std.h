/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_OPTIONS_STD_H

/* Reverse include guard */
enum guard_appl_options_std_h
{
    inc_appl_options_std_h =
        /* Header file dependencies */
        inc_appl_options_h
        + inc_appl_list_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

enum appl_options_std_state
{
    appl_options_std_state_space = 0,

    appl_options_std_state_word = 1,

    appl_options_std_state_escape = 2,

    appl_options_std_state_quote = 3

}; // enum appl_options_std_state

//
//
//
class appl_options_std : public appl_options
{
    public:

        static
        enum appl_status
        s_create(
            struct appl_allocator * const
                p_allocator,
            struct appl_options * * const
                r_options_std);

        static
        enum appl_status
        s_destroy(
            struct appl_allocator * const
                p_allocator,
            struct appl_options * const
                p_options_std);

        appl_options_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_options_std();

        enum appl_status
            f_init(void);

    protected:

    private:

        // list of words
        struct appl_list
            m_list;

        // --

        struct appl_chunk *
            m_chunk;

        unsigned long int
            m_count;

        enum appl_options_std_state
            m_state;

        bool
            m_chunk_created;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG + APPL_SIZEOF_INT + 1)
#include <misc/appl_padding.h>

        // --

        appl_options_std(
            class appl_options_std const & r);

        class appl_options_std &
            operator =(
                class appl_options_std const & r);

        void
            f_free_node_list(void);

        virtual
        appl_size_t
            v_cleanup(void);

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

        enum appl_status
            f_flush_word(void);

        enum appl_status
            f_append_char(
                unsigned char const
                    i_char);

        enum appl_status
            f_process_char(
                unsigned char const
                    i_char,
                char * const
                    p_ready);

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

        virtual
        enum appl_status
            v_reset(void);

}; // class appl_options_std

/* end-of-file: appl_options_std.h */
