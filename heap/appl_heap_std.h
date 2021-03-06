/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_heap_std_h
{
    inc_appl_heap_std_h =
        /* Header file dependency */
        inc_appl_heap_h
};

/* Assert compiler */
#include <misc/appl_assert_cplusplus.h>

class appl_heap_std;

//
//
//
class appl_heap_std : public appl_heap
{
    public:

        appl_heap_std(
            struct appl_context * const
                p_context);

        virtual
        ~appl_heap_std();

        enum appl_status
            f_init(void);

        virtual
        appl_size_t
            v_cleanup(void);

    protected:

    private:

        appl_heap_std(
            class appl_heap_std const & r);

        class appl_heap_std &
            operator =(
                class appl_heap_std const & r);

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

}; // class appl_heap_std

/* end-of-file: appl_heap_std.h */
