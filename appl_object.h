/* See LICENSE for license details */

/*

*/

#if defined(INC_APPL_OBJECT_H)
#error include appl_object.h once
#endif /* #if defined(INC_APPL_OBJECT_H) */

#define INC_APPL_OBJECT_H

/* Header file dependencies */
#if !defined(INC_APPL_TYPES_H)
#error include appl_types.h before
#endif /* #if !defined(INC_APPL_TYPES_H) */

struct appl_context;

struct appl_object;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

//
//
//
struct appl_object
{
    public:

        virtual
        enum appl_status
            v_destroy(void);

        struct appl_context *
            get_context(void) const;

        void
            set_context(
                struct appl_context * const
                    p_context);

        enum appl_status
            f_init(void);

    protected:

        // --

        // vtable[1u];

        struct appl_context *
            m_context;

        // --

        appl_object();

        virtual
        ~appl_object();

        virtual
        enum appl_status
            v_cleanup(void);

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

    private:

        appl_object(
            struct appl_object const & r);

        struct appl_object &
            operator =(
                struct appl_object const & r);

}; // struct appl_object

/* end-of-file: appl_object.h */
