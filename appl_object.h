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

        static
        enum appl_status
            create_instance(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (*p_new)(
                    void * const
                        p_placement),
                void const * const
                    p_descriptor,
                struct appl_object * * const
                    r_object);

        template <typename T_instance>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (*p_new)(
                    void * const
                        p_placement),
                T_instance * * const
                    r_type_instance)
        {
            return
                appl_object::create_instance(
                    p_context,
                    i_placement_length,
                    p_new,
                    static_cast<void const *>(
                        0),
                    reinterpret_cast<struct appl_object * *>(
                        r_type_instance));
        }

        template <typename T_descriptor, typename T_instance>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (*p_new)(
                    void * const
                        p_placement),
                T_descriptor const * const
                    p_type_descriptor,
                T_instance * * const
                    r_type_instance)
        {
            return
                appl_object::create_instance(
                    p_context,
                    i_placement_length,
                    p_new,
                    static_cast<void const *>(
                        p_type_descriptor),
                    reinterpret_cast<struct appl_object * *>(
                        r_type_instance));
        }

        static
        enum appl_status
            init_instance(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (*p_new)(
                    void * const
                        p_placement),
                void const * const
                    p_descriptor,
                struct appl_object * * const
                    r_object);

        template <typename T_instance>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (*p_new)(
                    void * const
                        p_placement),
                T_instance * * const
                    r_object)
        {
            return
                appl_object::init_instance(
                    p_context,
                    p_placement,
                    p_new,
                    static_cast<void const *>(
                        0),
                    reinterpret_cast<struct appl_object * *>(
                        r_object));
        }

        template <typename T_descriptor, typename T_instance>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (*p_new)(
                    void * const
                        p_placement),
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            return
                appl_object::init_instance(
                    p_context,
                    p_placement,
                    p_new,
                    static_cast<void const *>(
                        p_descriptor),
                    reinterpret_cast<struct appl_object * *>(
                        r_object));
        }

        virtual
        enum appl_status
            destroy(void);

        struct appl_context *
            get_context(void) const;

    protected:

        struct appl_context *
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

        class appl_object &
            operator =(
                struct appl_object const & r);

}; // class appl_object

/* end-of-file: appl_object.h */
