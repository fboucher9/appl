/* See LICENSE for license details */

/*

*/

/* Reverse include guard */
enum guard_appl_refcount_impl_h
{
    inc_appl_refcount_impl_h =
    inc_appl_refcount_h
};

//
//
//
class appl_refcount_impl
{
    public:

        appl_refcount_impl();

        ~appl_refcount_impl();

        enum appl_status
            f_init(void);

        enum appl_status
            f_cleanup(void);

    protected:

        struct appl_mutex *
            m_mutex;

        signed long int
            m_count;

#define PADDING (APPL_SIZEOF_PTR + APPL_SIZEOF_LONG)
#include <misc/appl_padding.h>

    private:

        appl_refcount_impl(
            class appl_refcount_impl const & r);

        class appl_refcount_impl &
            operator =(
                class appl_refcount_impl const & r);

}; // class appl_refcount_impl

/* end-of-file: appl_refcount_impl.h */
