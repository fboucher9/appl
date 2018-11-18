/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_allocator_h
{
    inc_appl_allocator_h =
        /* Header file dependency */
        inc_appl_object_h
};

/* Assert compiler */
#if ! defined __cplusplus
#error use c++ compiler
#endif /* #if ! defined __cplusplus */

// Predefine
struct appl_allocator;

//
//
//
struct appl_allocator : public appl_object
{
    public:

        virtual
        enum appl_status
            v_alloc(
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_buf);

        virtual
        enum appl_status
            v_free(
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

        template <typename T_instance>
        enum appl_status
            alloc_object(
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

            e_status =
                v_alloc(
                    sizeof(T_instance),
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                new (
                    o_object_ptr.p_placement)
                    T_instance;

                o_object_ptr.p_object->set_context(
                    m_context);

                o_object_ptr.p_object->set_allocator(
                    this);

                o_object_ptr.p_object->set_placement_length(
                    sizeof(T_instance));

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

                    v_free(
                        sizeof(T_instance),
                        o_object_ptr.p_placement);
                }
            }

            return
                e_status;

        } // alloc_object()

        template <typename T_instance, typename T_descriptor>
        enum appl_status
            alloc_object(
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

            e_status =
                v_alloc(
                    sizeof(T_instance),
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                new (
                    o_object_ptr.p_placement)
                    T_instance;

                o_object_ptr.p_object->set_context(
                    m_context);

                o_object_ptr.p_object->set_allocator(
                    this);

                o_object_ptr.p_object->set_placement_length(
                    sizeof(T_instance));

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

                    v_free(
                        sizeof(T_instance),
                        o_object_ptr.p_placement);
                }
            }

            return
                e_status;

        } // alloc_object()

    protected:

        appl_allocator();

        virtual
        ~appl_allocator();

    private:

        appl_allocator(
            struct appl_allocator const & r);

        struct appl_allocator &
            operator =(
                struct appl_allocator const & r);

}; // struct appl_allocator

/* end-of-file: appl_allocator.h */
