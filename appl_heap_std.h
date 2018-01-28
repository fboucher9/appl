/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
#if defined(INC_APPL_HEAP_STD_H)
#error include appl_heap_std.h once
#endif /* #if defined(INC_APPL_HEAP_STD_H) */

#define INC_APPL_HEAP_STD_H

#if !defined(__cplusplus)
#error use c++ compiler
#endif /* #if !defined(__cplusplus) */

class appl_heap_std;

//
//
//
class appl_heap_std : public appl_heap
{
    public:

        static
        enum appl_status
            create_instance(
                class appl_heap_std * * const
                    r_heap_std);

    protected:

        appl_heap_std();

        virtual
        ~appl_heap_std();

    private:

        appl_heap_std(
            class appl_heap_std const & r);

        class appl_heap_std &
            operator =(
                class appl_heap_std const & r);

        static
        void
            placement_new(
                void * const
                    p_placement)
        {
            new (p_placement)
                class appl_heap_std;
        }

        virtual
        enum appl_status
            destroy(void);

        virtual
        enum appl_status
            alloc_memory(
                struct appl_buf * const
                    p_buf,
                unsigned long int const
                    i_buf_len);

        virtual
        enum appl_status
            free_memory(
                struct appl_buf * const
                    p_buf);

        virtual
        enum appl_status
            realloc_memory(
                struct appl_buf * const
                    p_buf,
                unsigned long int const
                    i_buf_len);

}; // class appl_heap_std

/* end-of-file: appl_heap_std.h */
