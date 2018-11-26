/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_h
{
    inc_appl_heap_h =
        /* Header file dependency */
        inc_appl_allocator_h
};

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

// Predefine
struct appl_heap;

//
//
//
struct appl_heap : public appl_allocator
{
    public:

        template <typename T_instance>
        enum appl_status
            alloc_structure_array(
                appl_size_t const
                    i_count,
                T_instance * * const
                    r_object_array)
        {
            enum appl_status
                e_status;

            union object_ptr
            {
                void *
                    p_placement;

                T_instance *
                    p_instance;

            } o_object_ptr;

            e_status =
                v_alloc(
                    sizeof(
                        T_instance)
                    * i_count,
                    &(
                        o_object_ptr.p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                *(
                    r_object_array) =
                    o_object_ptr.p_instance;
            }

            return
                e_status;

        } // alloc_structure_array()

        template <typename T_instance>
        enum appl_status
            free_structure_array(
                appl_size_t const
                    i_count,
                T_instance * const
                    p_object_array)
        {
            enum appl_status
                e_status;

            union object_ptr
            {
                void *
                    p_placement;

                T_instance *
                    p_instance;

            } o_object_ptr;

            o_object_ptr.p_instance =
                p_object_array;

            e_status =
                v_free(
                    sizeof(
                        T_instance)
                    * i_count,
                    o_object_ptr.p_placement);

            return
                e_status;

        } // free_structure_array()

        template <typename T_instance>
        enum appl_status
            alloc_object(
                T_instance * * const
                    r_object)
        {
            return
                alloc_object(
                    sizeof(T_instance),
                    r_object);

        } // alloc_object()

        template <typename T_instance, typename T_descriptor>
        enum appl_status
            alloc_object(
                T_descriptor const * const
                    p_descriptor,
                T_instance * * const
                    r_object)
        {
            return
                alloc_object(
                    sizeof(T_instance),
                    p_descriptor,
                    r_object);

        } // alloc_object()

        template <typename T_instance, typename T_descriptor>
        enum appl_status
            alloc_object(
                appl_size_t const
                    i_placement_length,
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
                v_alloc(
                    i_placement_length,
                    &(
                        p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_object::init_object(
                        m_context,
                        this,
                        p_placement,
                        i_placement_length,
                        p_descriptor,
                        r_object);

                if (
                    appl_status_ok
                    != e_status)
                {
                    v_free(
                        i_placement_length,
                        p_placement);
                }
            }

            return
                e_status;

        } // s_create()

        template <typename T_instance>
        enum appl_status
            alloc_object(
                appl_size_t const
                    i_placement_length,
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            void *
                p_placement;

            e_status =
                v_alloc(
                    i_placement_length,
                    &(
                        p_placement));

            if (
                appl_status_ok
                == e_status)
            {
                e_status =
                    appl_object::init_object(
                        m_context,
                        this,
                        p_placement,
                        i_placement_length,
                        r_object);

                if (
                    appl_status_ok
                    != e_status)
                {
                    v_free(
                        i_placement_length,
                        p_placement);
                }
            }

            return
                e_status;

        } // s_create()

    protected:

        appl_heap();

        virtual
        ~appl_heap();

    private:

        appl_heap(
            struct appl_heap const & r);

        struct appl_heap &
            operator =(
                struct appl_heap const & r);

}; // struct appl_heap

/* end-of-file: appl_heap.h */
