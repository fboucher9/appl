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

struct appl_object_handle;

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_context;

class appl_object;

//
//
//
class appl_object
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (*p_new)(
                    void * const
                        p_placement),
                void const * const
                    p_descriptor,
                class appl_object * * const
                    r_object);

        static
        enum appl_status
            init_instance(
                class appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (*p_new)(
                    void * const
                        p_placement),
                void const * const
                    p_descriptor,
                class appl_object * * const
                    r_object);

        virtual
        enum appl_status
            destroy(void);

        static
        class appl_object *
            convert_handle(
                struct appl_object_handle * const
                    p_object_handle);

    protected:

        class appl_context *
            m_context;

        appl_object();

        virtual
        ~appl_object();

        virtual
        enum appl_status
            init(
                void const * const
                    p_descriptor);

        virtual
        enum appl_status
            cleanup(void);

        static
        void *
        operator new(
            appl_size_t const
                i_buf_len);

        static
        void
        operator delete(
            void * const
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
            void * const
                p_buf,
            void * const
                p_placement);

    private:

        appl_object(
            class appl_object const & r);

        class appl_object &
            operator =(
                class appl_object const & r);

}; // class appl_object

/* end-of-file: appl_object.h */
