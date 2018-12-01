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
            v_destroy(
                struct appl_allocator * const
                    p_allocator);

        struct appl_context *
            get_context(void) const;

        void
            set_context(
                struct appl_context * const
                    p_context);

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

        template <typename T_instance>
        static
        enum appl_status
            init_object(
                struct appl_context * const
                    p_context,
                void * const
                    p_placement,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

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

            new (
                o_object_ptr.p_placement)
                T_instance;

            o_object_ptr.p_object->set_context(
                p_context);

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

            if (
                appl_status_ok
                != e_status)
            {
                delete
                    o_object_ptr.p_instance;
            }

            return
                e_status;

        } // init_object()

        template <typename T_instance, typename T_descriptor>
        static
        enum appl_status
            init_object(
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

            new (
                o_object_ptr.p_placement)
                T_instance;

            o_object_ptr.p_object->set_context(
                p_context);

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

            if (
                appl_status_ok
                != e_status)
            {
                delete
                    o_object_ptr.p_instance;
            }

            return
                e_status;

        } // init_object()

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
        appl_size_t
            v_cleanup(void);

    private:

        appl_object(
            struct appl_object const & r);

        struct appl_object &
            operator =(
                struct appl_object const & r);

}; // struct appl_object

/* end-of-file: appl_object.h */
