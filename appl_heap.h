/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_H)
#error include appl_heap.h once
#endif /* #if defined(INC_APPL_HEAP_H) */

#define INC_APPL_HEAP_H

/* Header file dependency */
#if ! defined INC_APPL_OBJECT_H
#error include appl_object.h before appl_heap.h
#endif /* #if ! defined INC_APPL_OBJECT_H */

/* Assert compiler */
#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

struct appl_heap;

//
//
//
struct appl_heap : public appl_object
{
    public:

        virtual
        enum appl_status
            v_alloc(
                appl_size_t const
                    i_buf_len,
                void * * const
                    r_buf);

        template <typename T_instance>
        enum appl_status
            alloc_structure(
                T_instance * * const
                    r_object)
        {
            return
                v_alloc(
                    sizeof(
                        T_instance),
                    reinterpret_cast<void * *>(
                        r_object));

        } // alloc_object()

        template <typename T_instance>
        enum appl_status
            alloc_structure_array(
                unsigned long int
                    i_count,
                T_instance * * const
                    r_object_array)
        {
            return
                v_alloc(
                    sizeof(
                        T_instance)
                    * i_count,
                    reinterpret_cast<void * *>(
                        r_object_array));

        } // alloc_object_array()

        virtual
        enum appl_status
            v_free(
                appl_size_t const
                    i_buf_len,
                void * const
                    p_buf);

        template <typename T_instance>
        enum appl_status
            free_structure_array(
                unsigned long int
                    i_count,
                T_instance * const
                    p_object_array)
        {
            return
                v_free(
                    sizeof(
                        T_instance)
                    * i_count,
                    p_object_array);
        }

        template <typename T_instance>
        enum appl_status
            alloc_object(
                T_instance * * const
                    r_object)
        {
            enum appl_status
                e_status;

            void *
                p_placement;

            appl_size_t const
                i_placement_length =
                sizeof(T_instance);

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
                    appl_object::s_init<T_instance>(
                        m_context,
                        p_placement,
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

            void *
                p_placement;

            appl_size_t const
                i_placement_length =
                sizeof(T_instance);

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
                    appl_object::s_init<T_instance, T_descriptor>(
                        m_context,
                        p_placement,
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
                    appl_object::s_init<T_instance, T_descriptor>(
                        m_context,
                        p_placement,
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
                    appl_object::s_init<T_instance>(
                        m_context,
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
