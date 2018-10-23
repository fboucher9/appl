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
        enum appl_status
            init_object(
                void * const
                    p_placement,
                T_instance * * const
                    r_object)
        {
            return
                appl_object::s_init<T_instance>(
                    m_context,
                    p_placement,
                    sizeof(T_instance),
                    r_object);

        } // init_object()

        template <typename T_instance, typename T_descriptor>
        enum appl_status
            init_object(
                void * const
                    p_placement,
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            return
                appl_object::s_init<T_instance, T_descriptor>(
                    m_context,
                    p_placement,
                    p_descriptor,
                    r_object);

        } // init_object()

        template <typename T_instance>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            new (
                p_placement)
                T_instance;

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
                o_object_ptr.p_instance->f_init();

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

        template <typename T_instance, typename T_descriptor>
        static
        enum appl_status
            s_init(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            new (
                p_placement)
                T_instance;

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
                o_object_ptr.p_instance->f_init(
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

        virtual
        enum appl_status
            v_destroy(void);

        struct appl_context *
            get_context(void) const;

        void
            set_context(
                struct appl_context * const
                    p_context);

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

        enum appl_status
            f_init(void);

    private:

        appl_object(
            struct appl_object const & r);

        struct appl_object &
            operator =(
                struct appl_object const & r);

}; // struct appl_object

/* end-of-file: appl_object.h */
