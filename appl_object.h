/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined INC_APPL_OBJECT_H
#error include appl_object.h once
#endif /* #if defined INC_APPL_OBJECT_H */

#define INC_APPL_OBJECT_H

/* Header file dependencies */
#if !defined(INC_APPL_TYPES_H)
#error include appl_types.h before
#endif /* #if !defined(INC_APPL_TYPES_H) */

/* Predefine */
struct appl_context;

/* Predefine */
struct appl_object;

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
struct appl_allocator;

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

        struct appl_allocator *
            get_allocator(void) const;

        void
            set_allocator(
                struct appl_allocator * const
                    p_allocator);

        appl_size_t
            get_placement_length(void) const;

        void
            set_placement_length(
                appl_size_t const
                    i_placement_length);

        enum appl_status
            f_init(void);

    protected:

        // --

        // vtable[1u];

        struct appl_context *
            m_context;

        // --

        struct appl_allocator *
            m_allocator;

        appl_size_t
            m_placement_length;

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
