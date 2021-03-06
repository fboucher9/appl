/* See LICENSE for license details */

/*

*/

/* Included. */
#define INC_APPL_OBJECT_H

/* Reverse include guard */
enum guard_appl_object_h
{
    inc_appl_object_h =
        /* Header file dependency */
        inc_appl_types_h
        + inc_appl_status_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

//
//
//
struct appl_object
{
    public:

        appl_object(
            struct appl_context * const
                p_context);

        virtual
        ~appl_object();

        virtual
        appl_size_t
            v_cleanup(void);

        struct appl_context *
            get_context(void) const;

        enum appl_status
            f_init(void);

        static
        void *
        operator new(
            appl_size_t const
                i_buf_len);

        static
        void
        operator delete(
            void *
                p_buf);

        static
        void *
        operator new(
            appl_size_t const
                i_buf_len,
            void * const
                p_placement);

        static
        void
        operator delete (
            void *
                p_buf,
            void * const
                p_placement);

    protected:

        // --

        // vtable[1u];

        struct appl_context *
            m_context;

        // --

    private:

        appl_object(
            struct appl_object const & r);

        struct appl_object &
            operator =(
                struct appl_object const & r);

}; // struct appl_object

/* end-of-file: appl_object.h */
