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

        template <typename T_instance>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                void (* const p_new)(
                    void * const
                        p_placement),
                T_instance * * const
                    r_object)
        {
            return
                appl_object::s_create<T_instance>(
                    p_context,
                    sizeof(T_instance),
                    p_new,
                    (&
                        T_instance::init_dummy),
                    r_object);

        } // s_create()

        template <typename T_instance>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(void),
                T_instance * * const
                    r_object)
        {
            return
                appl_object::s_create<T_instance>(
                    p_context,
                    sizeof(T_instance),
                    p_new,
                    p_init,
                    r_object);

        } // s_create()

        template <typename T_instance, typename T_descriptor>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(
                    T_descriptor const * const
                        p_descriptor),
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            return
                appl_object::s_create<T_instance, T_descriptor>(
                    p_context,
                    sizeof(T_instance),
                    p_new,
                    p_init,
                    p_descriptor,
                    r_object);

        } // s_create()

        template <typename T_instance, typename T_descriptor>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(
                    T_descriptor const * const
                        p_descriptor),
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            void *
                p_placement;

            e_status =
                appl_object::alloc_placement(
                    p_context,
                    i_placement_length,
                    &(
                        p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_object::s_init<T_instance, T_descriptor>(
                        p_context,
                        p_placement,
                        p_new,
                        p_init,
                        p_descriptor,
                        r_object);

                if (
                    appl_status_ok
                    != e_status)
                {
                    appl_object::free_placement(
                        p_context,
                        p_placement);
                }
            }

            return
                e_status;

        } // s_create()

        template <typename T_instance>
        static
        enum appl_status
            s_create(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_placement_length,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(void),
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            void *
                p_placement;

            e_status =
                appl_object::alloc_placement(
                    p_context,
                    i_placement_length,
                    &(
                        p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_object::s_init<T_instance>(
                        p_context,
                        p_placement,
                        p_new,
                        p_init,
                        r_object);

                if (
                    appl_status_ok
                    != e_status)
                {
                    appl_object::free_placement(
                        p_context,
                        p_placement);
                }
            }

            return
                e_status;

        } // s_create()

        template <typename T_instance, typename T_descriptor>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(
                    T_descriptor const * const
                        p_descriptor),
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            (*p_new)(
                p_placement);

            union object_ptr
            {
                void *
                    p_placement;

                struct appl_object *
                    p_object;

                T_instance *
                    p_instance;

            } o_object_ptr;

            o_object_ptr.p_placement =
                p_placement;

            o_object_ptr.p_object->m_context =
                p_context;

            e_status =
                ((o_object_ptr.p_instance)->*(p_init))(
                    p_descriptor);

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_object) =
                    o_object_ptr.p_instance;
            }
            else
            {
                delete
                    o_object_ptr.p_object;
            }

            return
                e_status;

        } // s_init()

        template <typename T_instance>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                void (* const p_new)(
                    void * const
                        p_placement),
                enum appl_status (T_instance::* const p_init)(void),
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            (*p_new)(
                p_placement);

            union object_ptr
            {
                void *
                    p_placement;

                struct appl_object *
                    p_object;

                T_instance *
                    p_instance;

            } o_object_ptr;

            o_object_ptr.p_placement =
                p_placement;

            o_object_ptr.p_object->m_context =
                p_context;

            e_status =
                ((o_object_ptr.p_instance)->*(p_init))();

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_object) =
                    o_object_ptr.p_instance;
            }
            else
            {
                delete
                    o_object_ptr.p_object;
            }

            return
                e_status;

        } // s_init()

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

        enum appl_status
            init_dummy(void);

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

        static
        enum appl_status
            alloc_placement(
                struct appl_context * const
                    p_context,
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_placement);

        static
        void
            free_placement(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement);

}; // struct appl_object

/* end-of-file: appl_object.h */
