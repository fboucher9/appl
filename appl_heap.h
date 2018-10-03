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

class appl_heap;

//
//
//
class appl_heap : public appl_object
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
            alloc_object(
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
            alloc_object_array(
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
            free_object_array(
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

    protected:

        appl_heap();

        virtual
        ~appl_heap();

    private:

        appl_heap(
            class appl_heap const & r);

        class appl_heap &
            operator =(
                class appl_heap const & r);

}; // class appl_heap

/* end-of-file: appl_heap.h */
